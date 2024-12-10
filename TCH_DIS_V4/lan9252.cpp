
#include "lan9252.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <iostream>


#define SPI_DEVICE "/dev/spidev1.0" // Adjust SPI device as needed
#define SPI_MODE SPI_MODE_0
#define SPI_BITS_PER_WORD 8
#define SPI_SPEED 3000000

int spi_fd = -1;

// Global Buffers
PROCBUFFER Etc_Buffer_Out = {.LANByte = 0};
PROCBUFFER Etc_Buffer_In = {.LANByte = 0};

// SPI Transfer Function
bool spiTransfer(uint8_t* txBuffer, uint8_t* rxBuffer, uint32_t length) {
     struct spi_ioc_transfer spiTransfer = {};
    spiTransfer.tx_buf = reinterpret_cast<unsigned long>(txBuffer);
     spiTransfer.rx_buf = reinterpret_cast<unsigned long>(rxBuffer);
    spiTransfer .len = length;
     spiTransfer.speed_hz = SPI_SPEED;
    spiTransfer.bits_per_word = SPI_BITS_PER_WORD;
    spiTransfer.delay_usecs = 0;

    return ioctl(spi_fd, SPI_IOC_MESSAGE(1), &spiTransfer) >= 0;
}

// SPI Initialization
bool initSPI() {
    spi_fd = open(SPI_DEVICE, O_RDWR);
    if (spi_fd < 0) {
        std::cerr << "Error opening SPI device!" << std::endl;
        return false;
    }

    uint8_t mode = SPI_MODE;
    uint8_t bits = SPI_BITS_PER_WORD;
    uint32_t speed = SPI_SPEED;

    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &mode) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits) < 0 ||
        ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0) {
        std::cerr << "Error configuring SPI device!" << std::endl;
        close(spi_fd);
        return false;
    }

    return true;
}

// Read a directly addressable register
uint32_t Etc_Read_Reg(uint16_t address, uint8_t length) {
    ULONG Result;
    UWORD Addr;
    uint8_t i;
    uint8_t xfrbuf[7] = {0};
    ///uint8_t rxbuf[7] = {0};

    Addr.LANWord = address;
    xfrbuf[0] = COMM_SPI_READ;
    xfrbuf[1] = Addr.LANByte[1];
    xfrbuf[2] = Addr.LANByte[0];

    for (i = 0; i < length; i++) {
        xfrbuf[i + 3] = DUMMY_BYTE;
    }
    spiTransfer(xfrbuf, xfrbuf, length + 3);

    Result.LANLong = 0;
    for (i = 0; i < length; i++) {
        Result.LANByte[i] = xfrbuf[i + 3];
    }
    return Result.LANLong;
}

// Write a directly addressable register, 4 bytes always
void Etc_Write_Reg(uint16_t address, uint32_t DataOut) {
    ULONG Data;
    UWORD Addr;
    uint8_t i;
    uint8_t xfrbuf[7];

    Addr.LANWord = address;
    Data.LANLong = DataOut;

    xfrbuf[0] = COMM_SPI_WRITE;
    xfrbuf[1] = Addr.LANByte[1];
    xfrbuf[2] = Addr.LANByte[0];

    for (i = 0; i < 4; i++) {
        xfrbuf[i + 3] = Data.LANByte[i];
    }

    spiTransfer(xfrbuf, xfrbuf, 7);

}

// Read an indirectly addressable register
uint32_t Etc_Read_Reg_Wait(uint16_t address, uint8_t length) {
    ULONG TempLong;
    UWORD Addr;

    Addr.LANWord = address;

    TempLong.LANByte[0] = Addr.LANByte[0];
    TempLong.LANByte[1] = Addr.LANByte[1];
    TempLong.LANByte[2] = length;
    TempLong.LANByte[3] = ESC_READ;

    Etc_Write_Reg(ECAT_CSR_CMD, TempLong.LANLong);
    TempLong.LANByte[3] = ECAT_CSR_BUSY;

    do {
        TempLong.LANLong = Etc_Read_Reg(ECAT_CSR_CMD, 4);
    } while (TempLong.LANByte[3] & ECAT_CSR_BUSY);
    TempLong.LANLong = Etc_Read_Reg(ECAT_CSR_DATA, length);
    return TempLong.LANLong;
}

// Write an indirectly addressable register, 4 bytes always
void Etc_Write_Reg_Wait(uint16_t address, uint32_t DataOut) {
    ULONG TempLong;
    UWORD Addr;

    Addr.LANWord = address;
    Etc_Write_Reg(ECAT_CSR_DATA, DataOut);

    TempLong.LANByte[0] = Addr.LANByte[0];
    TempLong.LANByte[1] = Addr.LANByte[1];
    TempLong.LANByte[2] = 4;
    TempLong.LANByte[3] = ESC_WRITE;

    Etc_Write_Reg(ECAT_CSR_CMD, TempLong.LANLong);
    TempLong.LANByte[3] = ECAT_CSR_BUSY;

    do {
        TempLong.LANLong = Etc_Read_Reg(ECAT_CSR_CMD, 4);
    } while (TempLong.LANByte[3] & ECAT_CSR_BUSY);
}
// read from process ram fifo
void Etc_Read_Fifo()
{
    ULONG TempLong;
    uint8_t xfrbuf[35]; 										// buffer for spi xfr
    uint8_t i;

    Etc_Write_Reg(ECAT_PRAM_RD_ADDR_LEN, 0x00201000);   		// we always read 32 bytes (0x0020), output process ram offset 0x1000
    Etc_Write_Reg(ECAT_PRAM_RD_CMD, 0x80000000);        		// start command
    TempLong.LANLong = 0;
    do{                                                   		// wait for data to be transferred                                                   // from the output process ram
        TempLong.LANLong = Etc_Read_Reg(ECAT_PRAM_RD_CMD, 4); 	// to the read fifo
    }while (!(TempLong.LANByte[0] & PRAM_READ_AVAIL) || (TempLong.LANByte[1] != 8));

    xfrbuf[0] = COMM_SPI_READ;                                	// SPI read command
    xfrbuf[1] = 0x00;                                         	// address of the read
    xfrbuf[2] = 0x00;                                         	// fifo MsByte first
    for (i=0; i<32; i++)                                      	// 32 bytes dummy data
    {
        xfrbuf[i+3] = DUMMY_BYTE;
    }

    spiTransfer(xfrbuf, xfrbuf, 35);                            //send 35 bytes and get back into same buffer


    for (i=0; i<32; i++)                                   		// 32 bytes read data to usable buffer
    {
        Etc_Buffer_Out.LANByte[i] = xfrbuf[i+3];
    }
}
// write to the process ram fifo
void Etc_Write_Fifo()    										// write 32 bytes to the input process ram, through the fifo
{
    ULONG TempLong;
    uint8_t xfrbuf[35]; // buffer for spi xfr
    uint8_t i;

    Etc_Write_Reg(ECAT_PRAM_WR_ADDR_LEN, 0x00201200);   		// we always write 32 bytes (0x0020), input process ram offset 0x1200
    Etc_Write_Reg(ECAT_PRAM_WR_CMD, 0x80000000);        		// start command
    TempLong.LANLong = 0;
    do{                                                   		// check fifo has available space
        TempLong.LANLong = Etc_Read_Reg(ECAT_PRAM_WR_CMD, 4);	// for data to be written
    }
    while(!(TempLong.LANByte[0] & PRAM_WRITE_AVAIL) || (TempLong.LANByte[1] < 8));

    xfrbuf[0] = COMM_SPI_WRITE;                               	// SPI write command
    xfrbuf[1] = 0x00;                                         	// address of the write fifo
    xfrbuf[2] = 0x20;                                         	// MsByte first
    for (i=0; i<32; i++)                                      	// 32 bytes write loop
    {
        xfrbuf[i+3] = Etc_Buffer_In.LANByte[i];
    }
    //send 35 bytes and get back into same buffer
    spiTransfer(xfrbuf, xfrbuf, 35);

}


// Initialize / check the etc interface on SPI
bool etc_init() {
    ULONG TempLong;

    Etc_Write_Reg(RESET_CTL, (DIGITAL_RST & ETHERCAT_RST));
    usleep(100000);
    TempLong.LANLong = Etc_Read_Reg(BYTE_TEST, 4);

    if (TempLong.LANLong != 0x87654321) {
        return false;
    }

    TempLong.LANLong = Etc_Read_Reg(HW_CFG, 4);
    if ((TempLong.LANLong & READY) == 0) {  
        return false;
    }

    return true;
}


uint8_t etc_scan()
{
    bool WatchDog = 0;
    bool Operational = 0;
    uint8_t i;
    ULONG TempLong;
    uint8_t Status;

    TempLong.LANLong = Etc_Read_Reg_Wait(WDOG_STATUS, 1); 		// read watchdog status
    if ((TempLong.LANByte[0] & 0x01) == 0x01)
    {
       WatchDog = 0;                // set/reset the corresponding flag
    }
    else
    {
       WatchDog = 1;

    }

    TempLong.LANLong = Etc_Read_Reg_Wait(AL_STATUS_REG_0, 1);   // read the EtherCAT State Machine status
    Status = TempLong.LANByte[0] & 0x0F;
    if (Status == ESM_OP){                                     	// to see if we are in operational state
        Operational = 1;
    }else{
        Operational = 0;                                        // set/reset the corresponding flag

    }

    //--- process data transfert ----------
    if (WatchDog | !Operational)                              	// if watchdog is active or we are
    {                                                         	// not in operational state, reset
        for (i=0; i<8; i++){                                    // the output buffer
            Etc_Buffer_Out.LANLong[i] = 0;                      //
        }
    }else{

        Etc_Read_Fifo();                                        // otherwise transfer process data from
    }                                                         	// the EtherCAT core to the output buffer

    Etc_Write_Fifo();                                         	// we always transfer process data from
                                                                // the input buffer to the EtherCAT cor
    if (WatchDog)                                             	// return the status of the State Machine
    {                                                         	// and of the watchdog
        Status |= 0x80;
    }
    return Status;
}

