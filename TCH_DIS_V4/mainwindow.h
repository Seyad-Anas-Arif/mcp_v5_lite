#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define ALL_BUTTONS_RELEASED 0
#define CYCLE_START (1 << 0)
#define CYCLE_STOP  (1 << 1)
#define DRV_ON      (1 << 2)
#define JOG         (1 << 3)
#define X_AXIS      (1 << 4)
#define PLUS        (1 << 5)
#define Z_LOCK      (1 << 6)
#define MDI         (1 << 7)
#define Y_AXIS      (1 << 8)
#define VVV         (1 << 9)
#define DRY_RUN     (1 << 10)
#define AUTO        (1 << 11)
#define Z_AXIS      (1 << 12)
#define MINUS       (1 << 13)
#define NC_REF      (1 << 14)
#define NC_OFFSET   (1 << 15)
#define RET_FOR     (1 << 16)
#define RET_REV     (1 << 17)
#define PRC_END     (1 << 18)
#define ALM_OVR     (1 << 19)
#define ALM_RST     (1 << 20)
#define LOCK_RST    (1 << 21)
#define LASER_ON    (1 << 0)
class Ethercat : public QObject {
    Q_OBJECT

public:
    explicit Ethercat(QObject *parent = nullptr) {}
    ~Ethercat() {}

public slots:
    void etc_communication(); // Perform etc_scan() and emit updates

signals:
    void updateUI(int value); // Signal to notify the UI thread
};


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

    void on_retRevButton_pressed();

    void on_prcEndButton_pressed();

    void on_almOvrButton_pressed();

    void on_almRstButton_pressed();

    void on_lockRstButton_pressed();
private slots:
    void onUpdateUI(uint32_t etcOutValue);

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

    void on_retRevButton_released();

    void on_laserOnButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Ethercat *ethercat;
    QThread *etcThread;

};


#endif // MAINWINDOW_H
