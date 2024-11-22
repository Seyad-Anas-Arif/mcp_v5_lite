#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define ID_REV  0x0000
enum{
ALL_BUTTONS_UNPRESSED =0
,CYCLE_START_PRESSED
,CYCLE_STOP_PRESSED
,DRV_PRESSED
,JOG_PRESSED
,X_PRESSED
,PLUS_PRESSED
,Z_LOCK_PRESSED
,Y_PRESSED
,MDI_PRESSED
,VVV_PRESSED
,DRY_RUN_PRESSED
,AUTO_PRESSED
,Z_PRESSED
,MINUS_PRESSED
,NC_REF_PRESSED
,NC_OFFSET_PRESSED
,RET_FOR_PRESSED
,RET_REV_PRESSED
,PRC_END_PRESSED
,ALM_OVR_PRESSED
,ALM_RST_PRESSED
,LOCK_RST_PRESSED
,LASER_ON_PRESSED
,LASER_ON_UNPRESSED
} Btn_sts;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cycleStartButton_pressed();

    void on_cycleStopButton_pressed();

    void on_drvButton_pressed();

    void on_zLockButton_pressed();

    void on_dryRunButton_pressed();

    void on_jogButton_pressed();

    void on_mdiButton_pressed();

    void on_autoButton_pressed();

    void on_xButton_pressed();

    void on_yButton_pressed();

    void on_zButton_pressed();

    void on_plusButton_pressed();

    void on_vvvButton_pressed();

    void on_minusButton_pressed();

    void on_ncRefButton_pressed();

    void on_ncOffsetButton_pressed();

    void on_retForButton_pressed();

    void on_retRevButton_released();

    void on_prcEndButton_pressed();

    void on_almOvrButton_pressed();

    void on_almRstButton_pressed();

    void on_lockRstButton_pressed();

    void on_laserOnButton_clicked();
private slots:
    void updateUI(uint32_t etcOutValue);


    void on_cycleStartButton_released();

    void on_cycleStopButton_released();

    void on_mdiButton_released();

    void on_drvButton_released();

    void on_zLockButton_released();

    void on_dryRunButton_released();

    void on_jogButton_released();

    void on_autoButton_released();

    void on_xButton_released();

    void on_yButton_released();

    void on_zButton_released();

    void on_plusButton_released();

    void on_vvvButton_released();

    void on_minusButton_released();

    void on_ncRefButton_released();

    void on_ncOffsetButton_released();

    void on_retForButton_released();

    void on_prcEndButton_released();

    void on_almOvrButton_released();

    void on_almRstButton_released();

    void on_lockRstButton_released();

    void on_laserOnButton_released();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
