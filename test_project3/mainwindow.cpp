#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QPushButton"
#include <QApplication>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial.setPortName("ttyS0"); // Replace with the correct port name
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    //Laser ON LED indication
   //  ui->setupUi(this);
    // QPixmap pix("C:/Users/Sayedanasarif/Downloads/Red_led");
    // int w=ui->label_2->width();
    // int h=ui->label_2->height();
    // ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


    if (serial.open(QIODevice::ReadWrite)) {
        qDebug() << "Serial port opened successfully!";
    } else {
        qDebug() << "Failed to open serial port:" << serial.errorString();
    }
    QByteArray receivedData = serial.readAll();
    qDebug() << "Received data:" << receivedData;
    if(receivedData=="Ready"){
        QLabel *led= ui->label_2;
        led->setStyleSheet("background-color: green; color: black;");
    }


}

MainWindow::~MainWindow()
{
    QByteArray receivedData = serial.readAll();
    qDebug() << "Received data:" << receivedData;
    if(receivedData=="Ready"){
        QLabel *led= ui->label_2;
        led->setStyleSheet("background-color: green; color: black;");
    }

    // Close the serial port when the application is closed
    if (serial.isOpen()) {
        serial.close();
    }
    delete ui;
}
// This function is for to start the machine
void MainWindow::on_pushButton_clicked()
{
   //  QPushButton pushButton("START");
 //  pushButton. setStyleSheet("background-color: green; color: white;");
   QPushButton *StartPB=ui->pushButton;
   StartPB->setStyleSheet("background-color: green; color: black;");
   QPushButton *StopPB=ui->pushButton_2;
   StopPB->setStyleSheet("background-color: white; color: black;");
    QString dataToSend = "11";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
     qDebug() << "start Commend send!";
   // button.setStyleSheet("background-color: #3498db; color: #ffffff;"); // Blue background, white text
      startflag=true;

}

// To stop the machine
void MainWindow::on_pushButton_2_clicked()
{
    QPushButton *StartPB=ui->pushButton;
    StartPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *LaserPB=ui->pushButton_23;
    LaserPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *DrivePB=ui->pushButton_3;
    DrivePB->setStyleSheet("background-color: white; color: black;");
    QPushButton *ZlockPB=ui->pushButton_6;
    ZlockPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *DryPB=ui->pushButton_9;
    DryPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *jogPB=ui->pushButton_4;
    jogPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *mdiPB=ui->pushButton_7;
    mdiPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *AutoPB=ui->pushButton_10;
    AutoPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *XPB=ui->pushButton_5;
    XPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *YPB=ui->pushButton_8;
    YPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *ZPB=ui->pushButton_11;
    ZPB->setStyleSheet("background-color: white; color: black;");
    // QPushButton *laserPB=ui->pushButton_23;
    LaserPB->setStyleSheet("background-color: white; color: black;");

    QPushButton *StopPB=ui->pushButton_2;
    StopPB->setStyleSheet("background-color: red; color: black;");
    QString dataToSend = "00";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    startflag=false;
}

// To Turn on the Drive
void MainWindow::on_pushButton_3_clicked()
{
    if(startflag){
    QPushButton *DrivePB=ui->pushButton_3;
    DrivePB->setStyleSheet("background-color: green; color: black;");
    QString dataToSend = "12";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    }
}

//for Z-Axis Locks
void MainWindow::on_pushButton_6_clicked()
{
    if(startflag){
    QPushButton *ZlockPB=ui->pushButton_6;
    ZlockPB->setStyleSheet("background-color: green; color: black;");
    QString dataToSend = "13";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    }
}

// For dry run
void MainWindow::on_pushButton_9_clicked()
{
    if(startflag){
    QPushButton *DryPB=ui->pushButton_9;
    DryPB->setStyleSheet("background-color: green; color: black;");
    QString dataToSend = "14";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    }
}

//for jog mode
void MainWindow::on_pushButton_4_clicked()
{
    if(startflag){
    QPushButton *jogPB=ui->pushButton_4;
    jogPB->setStyleSheet("background-color: green; color: black;");
    QPushButton *mdiPB=ui->pushButton_7;
    mdiPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *AutoPB=ui->pushButton_10;
    AutoPB->setStyleSheet("background-color: white; color: black;");
    QString dataToSend = "15";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    }
}

//for MDI Mode
void MainWindow::on_pushButton_7_clicked()
{
    if(startflag){
    QPushButton *mdiPB=ui->pushButton_7;
    mdiPB->setStyleSheet("background-color: green; color: black;");
    QPushButton *jogPB=ui->pushButton_4;
    jogPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *AutoPB=ui->pushButton_10;
    AutoPB->setStyleSheet("background-color: white; color: black;");
    QString dataToSend = "16";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    }
}

//To run in Auto Mode
void MainWindow::on_pushButton_10_clicked()
{
    if(startflag){
    QPushButton *AutoPB=ui->pushButton_10;
    AutoPB->setStyleSheet("background-color: green; color: black;");
    QPushButton *jogPB=ui->pushButton_4;
    jogPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *mdiPB=ui->pushButton_7;
    mdiPB->setStyleSheet("background-color: white; color: black;");
    QString dataToSend = "17";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    }
}

//To choose X-Axis
void MainWindow::on_pushButton_5_clicked()
{
    if(startflag){
    QPushButton *XPB=ui->pushButton_5;
    XPB->setStyleSheet("background-color: green; color: black;");
    QPushButton *YPB=ui->pushButton_8;
    YPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *ZPB=ui->pushButton_11;
    ZPB->setStyleSheet("background-color: white; color: black;");
    QString dataToSend = "18";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    }
}

//To choose Y-Axis
void MainWindow::on_pushButton_8_clicked()
{
    if(startflag){
    QPushButton *XPB=ui->pushButton_5;
    XPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *YPB=ui->pushButton_8;
    YPB->setStyleSheet("background-color: green; color: black;");
    QPushButton *ZPB=ui->pushButton_11;
    ZPB->setStyleSheet("background-color: white; color: black;");
    QString dataToSend = "19";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    }
}
//To choose Z_ Axis
void MainWindow::on_pushButton_11_clicked()
{
    if(startflag){
    QPushButton *XPB=ui->pushButton_5;
    XPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *YPB=ui->pushButton_8;
    YPB->setStyleSheet("background-color: white; color: black;");
    QPushButton *ZPB=ui->pushButton_11;
    ZPB->setStyleSheet("background-color: green; color: black;");
    QString dataToSend = "20";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
    }
}

// To Move forward in selected Axis
void MainWindow::on_pushButton_12_clicked()
{

    QString dataToSend = "21";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

// To Reset Moments and come back to Zero
void MainWindow::on_pushButton_13_clicked()
{
    QString dataToSend = "22";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

// To move Reverse in choosen Axis
void MainWindow::on_pushButton_14_clicked()
{
    QString dataToSend = "23";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

//Nc-Ref value
void MainWindow::on_pushButton_18_clicked()
{
    QString dataToSend = "24";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

//for Nc-Offset
void MainWindow::on_pushButton_17_clicked()
{
    QString dataToSend = "25";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

// For Retrace Forward
void MainWindow::on_pushButton_16_clicked()
{
    QString dataToSend = "26";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}


//For Retrace Reverse
void MainWindow::on_pushButton_15_clicked()
{
    QString dataToSend = "27";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

// For Piercing End
void MainWindow::on_pushButton_22_clicked()
{
    QString dataToSend = "28";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

//For Alarm over
void MainWindow::on_pushButton_21_clicked()
{
    QString dataToSend = "29";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

//Alarm Rest
void MainWindow::on_pushButton_20_clicked()
{
    QString dataToSend = "30";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

//Lock Reset
void MainWindow::on_pushButton_19_clicked()
{
    QPushButton *ZlockPB=ui->pushButton_6;
    ZlockPB->setStyleSheet("background-color: white; color: black;");
    QString dataToSend = "31";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
}

//Laser ON
void MainWindow::on_pushButton_23_clicked()
{if(startflag){
    QPushButton *LaserPB=ui->pushButton_23;
    LaserPB->setStyleSheet("background-color: green; color: black;");
     qDebug() << "Laser on cmd transmitted!";
    QString dataToSend = "32";
    QByteArray sendData = dataToSend.toUtf8(); // Convert QString to QByteArray
    serial.write(sendData); // Send data via the serial port
  //   ui->setupUi(this);
    // QPixmap pix("C:/Users/Sayedanasarif/Downloads/Green");
    // int w=ui->label_2->width();
    // int h=ui->label_2->height();
    // ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

