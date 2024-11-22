/*
 * lan9252.cpp
 *
 * Created on: May 22, 2024
 * Author: LAB / Rajdeep
 */

#include "lan9252.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <iostream>
#include <cstring>

#define SPI_DEVICE "/dev/spidev0.0" // Adjust SPI device as needed
#define SPI_MODE SPI_MODE_0
#define SPI_BITS_PER_WORD 8
#define SPI_SPEED 5000000
#define LAN9252_CS_GPIO_Port A
#define LAN9252_CS_Pin 1

// #define CS_SET()  writePin(LAN9252_CS_GPIO_Port, LAN9252_CS_Pin, 0)
// #define CS_RESET() writePin(LAN9252_CS_GPIO_Port, LAN9252_CS_Pin, 1)

int spi_fd = -1;

// Global Buffers
PROCBUFFER Etc_Buffer_Out = {.LANByte = 0};
PROCBUFFER Etc_Buffer_In = {.LANByte = 0};

// Utility to write GPIO (replace with your implementation)
// void writePin(const char* port, int pin, int value) {
//     // Replace this with GPIO control logic
//     // Dummy for now
// }

// SPI Transfer Function
bool spiTransfer(uint8_t* txBuffer, uint8_t* rxBuffer, uint32_t length) {
    struct spi_ioc_transfer spiTransfer = {
        .tx_buf = reinterpret_cast<unsigned long>(txBuffer),
        .rx_buf = reinterpret_cast<unsigned long>(rxBuffer),
        .len = length,
        .speed_hz = SPI_SPEED,
        .bits_per_word = SPI_BITS_PER_WORD,
        //.delay_usecs = 0
    };

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
    uint8_t rxbuf[7] = {0};

    Addr.LANWord = address;
    xfrbuf[0] = COMM_SPI_READ;
    xfrbuf[1] = Addr.LANByte[1];
    xfrbuf[2] = Addr.LANByte[0];

    for (i = 0; i < length; i++) {
        xfrbuf[i + 3] = DUMMY_BYTE;
    }

    // CS_SET();
    spiTransfer(xfrbuf, rxbuf, length + 3);
    //CS_RESET();

    Result.LANLong = 0;
    for (i = 0; i < length; i++) {
        Result.LANByte[i] = rxbuf[i + 3];
    }
    return Result.LANLong;
}

// Write a directly addressable register, 4 bytes always
void Etc_Write_Reg(uint16_t address, uint32_t DataOut) {
    ULONG Data;
    UWORD Addr;
    uint8_t i;
    uint8_t xfrbuf[7] = {0};

    Addr.LANWord = address;
    Data.LANLong = DataOut;

    xfrbuf[0] = COMM_SPI_WRITE;
    xfrbuf[1] = Addr.LANByte[1];
    xfrbuf[2] = Addr.LANByte[0];

    for (i = 0; i < 4; i++) {
        xfrbuf[i + 3] = Data.LANByte[i];
    }

    //CS_SET();
    spiTransfer(xfrbuf, nullptr, 7);
    //CS_RESET();
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

    return Etc_Read_Reg(ECAT_CSR_DATA, length);
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

// Initialize / check the etc interface on SPI
bool etc_init() {
    ULONG TempLong;

    Etc_Write_Reg(RESET_CTL, (DIGITAL_RST & ETHERCAT_RST));
    usleep(100000);
    TempLong.LANLong = Etc_Read_Reg(BYTE_TEST, 4);

    if (TempLong.LANLong != 0x87654321) {
        std::cerr << "Bad response received from Etc Test command, data received = "
                  << TempLong.LANLong << std::endl;
        return false;
    }

    TempLong.LANLong = Etc_Read_Reg(HW_CFG, 4);
    if ((TempLong.LANLong & READY) == 0) {
        std::cerr << "Ready not received from Etc HW Cfg, data received = "
                  << TempLong.LANLong << std::endl;
        return false;
    }

    return true;
}

// Remaining functions (Etc_Read_Fifo, Etc_Write_Fifo, etc_scan) remain identical with SPI adapted.
