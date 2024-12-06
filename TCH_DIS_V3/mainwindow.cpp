#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lan9252.h"
#include "lan9252.cpp"
#include <iostream>

#include <QTimer>
#include <QThread>

bool islaseron_flag =false;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ethercat(new Ethercat), etcThread(new QThread)
{
    ui->setupUi(this);

    initSPI();
    if(etc_init()){
        cout<< "ethercat initiated success fully"<<endl;
    }
    else {
        cout<<"Problem in ethercat initialization "<<endl;
        etc_init();
    }
    //to archive continuous ethercat scanning and updating ui  starting etc_ communication in threads
    ethercat->moveToThread(etcThread);
    connect(etcThread, &QThread::started, ethercat, &Ethercat::etc_communication);
    connect(ethercat, &Ethercat::updateUI, this, &MainWindow::onUpdateUI);
    etcThread->start();

}

MainWindow::~MainWindow()
{
    etcThread->quit();
    etcThread->wait();
    delete ethercat;

    delete ui;
}
// button values fetching into ethetrcat  transmit buffer.
class Button_status{
public:
    void handle_button_pressed(int pressed_button_value){
        if (islaseron_flag){
            Etc_Buffer_In.LANLong[0] = pressed_button_value | (1<<5);
        }
        else {
          Etc_Buffer_In.LANLong[0] = pressed_button_value;
        }
    }

    void handle_button_released(){
        if (islaseron_flag){
            Etc_Buffer_In.LANLong[0] =(1<<5);
        }
        else {
             Etc_Buffer_In.LANLong[0] = ALL_BUTTONS_UNPRESSED;
        }
    }
}btn_sts;
/*-----------------------------------------------------------------Etehercat communication function----------------------------------------------*/
void Ethercat::etc_communication() {
    while (true) {    
        etc_scan(); // Simulated EtherCAT scan
        uint32_t etc_out_signal = Etc_Buffer_Out.LANLong[0];
        emit updateUI(etc_out_signal); // Emit signal to update the UI
        QThread::msleep(10); // Simulate delay
    }

}
/*-----------------------------------------------------------------Button Pressed section----------------------------------------*/
void MainWindow::on_cycleStartButton_pressed()
{

    btn_sts.handle_button_pressed(CYCLE_START_PRESSED);
}


void MainWindow::on_cycleStopButton_pressed()
{
    btn_sts.handle_button_pressed(CYCLE_STOP_PRESSED);
}



void MainWindow::on_drvButton_pressed()
{
    btn_sts.handle_button_pressed(DRV_PRESSED);
}


void MainWindow::on_zLockButton_pressed()
{
    btn_sts.handle_button_pressed(Z_LOCK_PRESSED);
}


void MainWindow::on_dryRunButton_pressed()
{
    btn_sts.handle_button_pressed(DRY_RUN_PRESSED);
}


void MainWindow::on_jogButton_pressed()
{

    btn_sts.handle_button_pressed(JOG_PRESSED);
}


void MainWindow::on_mdiButton_pressed()
{
    btn_sts.handle_button_pressed(MDI_PRESSED);
}


void MainWindow::on_autoButton_pressed()
{
    btn_sts.handle_button_pressed(AUTO_PRESSED);
}


void MainWindow::on_xButton_pressed()
{
    btn_sts.handle_button_pressed(X_PRESSED);
}


void MainWindow::on_yButton_pressed()
{
    btn_sts.handle_button_pressed(Y_PRESSED);
}


void MainWindow::on_zButton_pressed()
{
    btn_sts.handle_button_pressed(Z_PRESSED);
}


void MainWindow::on_plusButton_pressed()
{
    btn_sts.handle_button_pressed(PLUS_PRESSED);
}


void MainWindow::on_vvvButton_pressed()
{

    btn_sts.handle_button_pressed(VVV_PRESSED);
}


void MainWindow::on_minusButton_pressed()
{
    btn_sts.handle_button_pressed(MINUS_PRESSED);
}


void MainWindow::on_ncRefButton_pressed()
{
    btn_sts.handle_button_pressed(NC_REF_PRESSED);
}


void MainWindow::on_ncOffsetButton_pressed()
{
    btn_sts.handle_button_pressed(NC_OFFSET_PRESSED);
}


void MainWindow::on_retForButton_pressed()
{
    btn_sts.handle_button_pressed(RET_FOR_PRESSED);
}


void MainWindow::on_retRevButton_pressed()
{
    btn_sts.handle_button_pressed(RET_REV_PRESSED);
}


void MainWindow::on_prcEndButton_pressed()
{
    btn_sts.handle_button_pressed(PRC_END_PRESSED);
}


void MainWindow::on_almOvrButton_pressed()
{
    btn_sts.handle_button_pressed(ALM_OVR_PRESSED);
}


void MainWindow::on_almRstButton_pressed()
{
    btn_sts.handle_button_pressed(ALM_RST_PRESSED);
}


void MainWindow::on_lockRstButton_pressed()
{
    btn_sts.handle_button_pressed(LOCK_RST_PRESSED);
}


/*----------------------------------------------------release conditions----------------------------------------------------------------------------------*/
void MainWindow::on_cycleStartButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_cycleStopButton_released()
{
    btn_sts.handle_button_released();
}



void MainWindow::on_drvButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_zLockButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_dryRunButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_jogButton_released()
{
    btn_sts.handle_button_released();
}

void MainWindow::on_mdiButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_autoButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_xButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_yButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_zButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_plusButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_vvvButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_minusButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_ncRefButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_ncOffsetButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_retForButton_released()
{
    btn_sts.handle_button_released();
}
void MainWindow::on_retRevButton_released()
{
 btn_sts.handle_button_released();
}

void MainWindow::on_prcEndButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_almOvrButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_almRstButton_released()
{
    btn_sts.handle_button_released();
}


void MainWindow::on_lockRstButton_released()
{
    btn_sts.handle_button_released();
}

// Laser on/off button
void MainWindow::on_laserOnButton_toggled(bool checked)
{
    if (checked){
         islaseron_flag=true;
        btn_sts.handle_button_pressed(0);
        ui->laserOnButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");

    }
    else {
        islaseron_flag=false;
        btn_sts.handle_button_released();
        ui->laserOnButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");

    }
}



/*-------------------------------------------------------------------changing pushButton color-----------------------------------------*/
void MainWindow::onUpdateUI(uint32_t etcOutValue) {
    // Check if the 0th bit is set
    if (etcOutValue & (1 << 0)) {
        ui->cycleStartButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");

    } else {
        ui->cycleStartButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 1st bit is set
    if (etcOutValue & (1 << 1)) {
        ui->cycleStopButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->cycleStopButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 2nd bit is set
    if (etcOutValue & (1 << 2)) {
        ui->drvButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->drvButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 3rd bit is set
    if (etcOutValue & (1 << 3)) {
        ui->jogButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->jogButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 4th bit is set
    if (etcOutValue & (1 << 4)) {
        ui->xButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->xButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 5th bit is set
    if (etcOutValue & (1 << 5)) {
        ui->plusButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->plusButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 6th bit is set
    if (etcOutValue & (1 << 6)) {
        ui->zLockButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->zLockButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 7th bit is set
    if (etcOutValue & (1 << 7)) {
        ui->mdiButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->mdiButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 8th bit is set
    if (etcOutValue & (1 << 8)) {
        ui->yButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->yButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 9th bit is set
    if (etcOutValue & (1 << 9)) {
        ui->vvvButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->vvvButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 10th bit is set
    if (etcOutValue & (1 << 10)) {
        ui->dryRunButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->dryRunButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 11th bit is set
    if (etcOutValue & (1 << 11)) {
        ui->autoButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->autoButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 12th bit is set
    if (etcOutValue & (1 << 12)) {
        ui->zButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->zButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 13th bit is set
    if (etcOutValue & (1 << 13)) {
        ui->minusButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->minusButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 14th bit is set
    if (etcOutValue & (1 << 14)) {
        ui->ncRefButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->ncRefButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 15th bit is set
    if (etcOutValue & (1 << 15)) {
        ui->ncOffsetButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->ncOffsetButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 16th bit is set
    if (etcOutValue & (1 << 16)) {
        ui->retForButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->retForButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 17th bit is set
    if (etcOutValue & (1 << 17)) {
        ui->retRevButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->retRevButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 18th bit is set
    if (etcOutValue & (1 << 18)) {
        ui->prcEndButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->prcEndButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 19th bit is set
    if (etcOutValue & (1 << 19)) {
        ui->almOvrButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->almOvrButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 20th bit is set
    if (etcOutValue & (1 << 20)) {
        ui->almRstButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->almRstButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }

    // Check if the 21st bit is set
    if (etcOutValue & (1 << 21)) {
        ui->lockRstButton->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48);");
    } else {
        ui->lockRstButton->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);");
    }


    // Check if the 23rd bit is set
    if (etcOutValue & (1 << 22)) {
        ui->laserReadyLamp->setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px");
    } else {
        ui->laserReadyLamp->setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); border-radius: 65px");
    }
}
