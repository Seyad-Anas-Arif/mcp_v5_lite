# Laser on corrected but commented else for laser on button

from PyQt5 import QtWidgets, QtCore
from PyQt5.QtCore import Qt, QThread, pyqtSlot
import ctypes
import sys
import time

from ctypes import c_uint32
from Ethercat import EtherCATInterface
from home import Ui_MainWindow

# Constants for button presses as integers
CYCLE_START_PRESSED = 1
CYCLE_STOP_PRESSED = 2
DRV_PRESSED = 3
JOG_PRESSED = 4
X_PRESSED = 5
PLUS_PRESSED = 6
Z_LOCK_PRESSED = 7
MDI_PRESSED = 8
Y_PRESSED = 9
VVV_PRESSED = 10
DRY_RUN_PRESSED = 11
AUTO_PRESSED = 12
Z_PRESSED = 13
MINUS_PRESSED = 14
NC_REF_PRESSED = 15
NC_OFFSET_PRESSED = 16
RET_FOR_PRESSED = 17
RET_REV_PRESSED = 18
PRC_END_PRESSED = 19
ALM_OVR_PRESSED = 20
ALM_RST_PRESSED = 21
LOCK_RST_PRESSED = 22
LASER_ON_PRESSED = 23
LASER_ON_UNPRESSED = 24
ALL_BUTTONS_UNPRESSED = 0
ID_REV = 0x0000  # Dummy address for demonstration

# Global variable definition
CURRENT_STATE = ""

# Define output variables as unsigned 32-bit integers
etc_out = c_uint32(0)

class EtherCATThread(QThread):
    # Define a signal to send the etc_out value to the main thread
    data_ready = QtCore.pyqtSignal(int)

    def __init__(self, parent=None):
        super().__init__(parent)
        self.etc_interface = EtherCATInterface()
        self.etc_init_ok = False

    def run(self):
        # Initialize EtherCAT interface
        self.etc_init_ok = self.etc_interface.etc_init()
        # Read EtherCAT chip ID
        chip_id = self.etc_interface.read_reg(ID_REV, 4)  # Using a dummy ID_REV address
        print("EtherCAT Chip ID:", chip_id)

        while True:
            # Simulate scanning for EtherCAT data (replace with actual scan function)
            if self.etc_init_ok:
                try:
                    etc_out_value = 0
                    self.etc_interface.etc_scan()
                    # Read data from Etc_Buffer_Out (data sent from TwinCAT)
                    etc_out_value = self.etc_interface.Etc_Buffer_Out.LANLong[0]

                    # Emit the signal with the etc_out value
                    self.data_ready.emit(etc_out_value)

                except Exception as e:
                    print(f"Error during EtherCAT scan: {e}")
            else:
                print("Not Initialized\n")
                self.etc_init_ok = self.etc_interface.etc_init()

            # Wait for 0.3 seconds before the next iteration
            time.sleep(0.3)

def handle_button_press(button_pressed_value):
    print(f"Button {button_pressed_value} pressed\n")
    global CURRENT_STATE
    CURRENT_STATE = f"Button {button_pressed_value} pressed"
    etc_thread.etc_interface.Etc_Buffer_In.LANLong[0] = button_pressed_value

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    MainWindow.setWindowFlags(Qt.FramelessWindowHint)
    MainWindow.showFullScreen()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)

    # Start the EtherCAT thread
    etc_thread = EtherCATThread()
    etc_thread.start()

    # Connect the EtherCAT thread signal to update UI elements
    def update_ui(etc_out_value):
        # Check if the 0th bit is set
        if etc_out_value & (1 << 0):
            ui.cycleStartButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 0px")
        else:
            ui.cycleStartButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);")
            
        # Check if the 1st bit is set
        if etc_out_value & (1 << 1):
            ui.cycleStopButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 0px")
        else:
            ui.cycleStopButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);")

        # Check if the 2nd bit is set
        if etc_out_value & (1 << 2):
            ui.drvButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.drvButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);")

        # Check if the 3rd bit is set
        if etc_out_value & (1 << 3):
            ui.jogButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.jogButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

         # Check if the 4th bit is set
        if etc_out_value & (1 << 4):
            ui.xButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.xButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 5th bit is set
        if etc_out_value & (1 << 5):
            ui.plusButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.plusButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 6th bit is set
        if etc_out_value & (1 << 6):
            ui.zLockButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.zLockButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 7th bit is set    
        if etc_out_value & (1 << 7):
           ui.mdiButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.mdiButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 8th bit is set
        if etc_out_value & (1 << 8):
             ui.yButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.yButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 9th bit is set
        if etc_out_value & (1 << 9):
            ui.vvvButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.vvvButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

         # Check if the 10th bit is set
        if etc_out_value & (1 << 10):
             ui.dryRunButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.dryRunButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 11th bit is set
        if etc_out_value & (1 << 11):
            ui.autoButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.autoButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 12th bit is set
        if etc_out_value & (1 << 12):
            ui.zButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.zButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 13th bit is set
        if etc_out_value & (1 << 13):
            ui.minusButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.minusButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 14th bit is set
        if etc_out_value & (1 << 14):
            ui.ncRefButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.ncRefButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 15th bit is set
        if etc_out_value & (1 << 15):
            ui.ncOffsetButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.ncOffsetButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 16th bit is set
        if etc_out_value & (1 << 16):
            ui.retForButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.retForButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);")

        # Check if the 17th bit is set
        if etc_out_value & (1 << 17):
            ui.retRevButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.retRevButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);")

        # Check if the 18th bit is set
        if etc_out_value & (1 << 18):
            ui.prcEndButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.prcEndButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48);")

        # Check if the 19th bit is set
        if etc_out_value & (1 << 19):
            ui.almOvrButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.almOvrButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 20th bit is set
        if etc_out_value & (1 << 20):
            ui.almRstButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.almRstButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 21st bit is set
        if etc_out_value & (1 << 21):
            ui.lockRstButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.lockRstButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); ")

        # Check if the 23rd bit is set
        if etc_out_value & (1 << 23):
            ui.laserReadyLamp.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48); border-radius: 65px")
        else:
            ui.laserReadyLamp.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48); border-radius: 65px")



    # Connect the data_ready signal from the EtherCAT thread to update_ui function
    etc_thread.data_ready.connect(update_ui)

    # Button press slots
    @pyqtSlot()
    def cycle_start_function():
        handle_button_press(CYCLE_START_PRESSED)

    @pyqtSlot()
    def cycle_stop_function():
        handle_button_press(CYCLE_STOP_PRESSED)

    @pyqtSlot()
    def drv_function():
        handle_button_press(DRV_PRESSED)

    @pyqtSlot()
    def z_lock_function():
        handle_button_press(Z_LOCK_PRESSED)

    @pyqtSlot()
    def dry_run_function():
        handle_button_press(DRY_RUN_PRESSED)

    @pyqtSlot()
    def jog_function():
        handle_button_press(JOG_PRESSED)

    @pyqtSlot()
    def mdi_function():
        handle_button_press(MDI_PRESSED)

    @pyqtSlot()
    def auto_function():
        handle_button_press(AUTO_PRESSED)

    @pyqtSlot()
    def x_jog_function():
        handle_button_press(X_PRESSED)

    @pyqtSlot()
    def y_jog_function():
        handle_button_press(Y_PRESSED)

    @pyqtSlot()
    def z_jog_function():
        handle_button_press(Z_PRESSED)

    @pyqtSlot()
    def plus_jog_function():
        handle_button_press(PLUS_PRESSED)

    @pyqtSlot()
    def minus_jog_function():
        handle_button_press(MINUS_PRESSED)

    @pyqtSlot()
    def vvv_jog_function():
        handle_button_press(VVV_PRESSED)

    @pyqtSlot()
    def nc_ref_function():
        handle_button_press(NC_REF_PRESSED)

    @pyqtSlot()
    def nc_offset_function():
        handle_button_press(NC_OFFSET_PRESSED)

    @pyqtSlot()
    def ret_for_function():
        handle_button_press(RET_FOR_PRESSED)

    @pyqtSlot()
    def ret_rev_function():
        handle_button_press(RET_REV_PRESSED)

    @pyqtSlot()
    def prc_end_function():
        handle_button_press(PRC_END_PRESSED)

    @pyqtSlot()
    def alm_ovr_function():
        handle_button_press(ALM_OVR_PRESSED)

    @pyqtSlot()
    def alm_rst_function():
        handle_button_press(ALM_RST_PRESSED)

    @pyqtSlot()
    def lock_rst_function():
        handle_button_press(LOCK_RST_PRESSED)

    @QtCore.pyqtSlot()
    def laser_on_function():
        if ui.laserOnButton.isChecked():
            ui.laserOnButton.setStyleSheet("background-color: rgb(250, 122, 72); color: rgb(48, 48, 48)")
            handle_button_press(LASER_ON_PRESSED)
            #serial_send(LASER_ON_PRESSED)
        else:
            ui.laserOnButton.setStyleSheet("background-color: rgb(96, 96, 96); color: rgb(48, 48, 48)")
            handle_button_press(LASER_ON_UNPRESSED)
            #serial_send(LASER_ON_UNPRESSED)

    
    # @pyqtSlot()
    # def laser_on_function():
    #     if ui.laserOnButton.isChecked():
    #         ui.laserOnButton.setStyleSheet("color: rgb(250, 122, 72)")
    #         handle_button_press(LASER_ON_PRESSED)
    #     else:
    #         ui.laserOnButton.setStyleSheet("color: rgb(48, 48, 48)")
    #         handle_button_press(LASER_ON_UNPRESSED)

    @pyqtSlot()
    def unpressed_function():
        global CURRENT_STATE
        # print(f"You released {CURRENT_STATE}\n")
        handle_button_press(ALL_BUTTONS_UNPRESSED)

    # Connect buttons to functions
    ui.cycleStartButton.pressed.connect(cycle_start_function)
    ui.cycleStopButton.pressed.connect(cycle_stop_function)
    ui.drvButton.pressed.connect(drv_function)
    ui.zLockButton.pressed.connect(z_lock_function)
    ui.dryRunButton.pressed.connect(dry_run_function)
    ui.jogButton.pressed.connect(jog_function)
    ui.mdiButton.pressed.connect(mdi_function)
    ui.autoButton.pressed.connect(auto_function)
    ui.xButton.pressed.connect(x_jog_function)
    ui.yButton.pressed.connect(y_jog_function)
    ui.zButton.pressed.connect(z_jog_function)
    ui.plusButton.pressed.connect(plus_jog_function)
    ui.vvvButton.pressed.connect(vvv_jog_function)
    ui.minusButton.pressed.connect(minus_jog_function)
    ui.ncRefButton.pressed.connect(nc_ref_function)
    ui.ncOffsetButton.pressed.connect(nc_offset_function)
    ui.retForButton.pressed.connect(ret_for_function)
    ui.retRevButton.pressed.connect(ret_rev_function)
    ui.prcEndButton.pressed.connect(prc_end_function)
    ui.almOvrButton.pressed.connect(alm_ovr_function)
    ui.almRstButton.pressed.connect(alm_rst_function)
    ui.lockRstButton.pressed.connect(lock_rst_function)
    
    # ui.laserOnButton.pressed.connect(laser_on_function)

    # Handle button release
    ui.cycleStartButton.released.connect(lambda: unpressed_function())
    ui.cycleStopButton.released.connect(lambda: unpressed_function())
    ui.drvButton.released.connect(lambda: unpressed_function())
    ui.zLockButton.released.connect(lambda: unpressed_function())
    ui.dryRunButton.released.connect(lambda: unpressed_function())
    ui.jogButton.released.connect(lambda: unpressed_function())
    ui.mdiButton.released.connect(lambda: unpressed_function())
    ui.autoButton.released.connect(lambda: unpressed_function())
    ui.xButton.released.connect(lambda: unpressed_function())
    ui.yButton.released.connect(lambda: unpressed_function())
    ui.zButton.released.connect(lambda: unpressed_function())
    ui.plusButton.released.connect(lambda: unpressed_function())
    ui.vvvButton.released.connect(lambda: unpressed_function())
    ui.minusButton.released.connect(lambda: unpressed_function())
    ui.ncRefButton.released.connect(lambda: unpressed_function())
    ui.ncOffsetButton.released.connect(lambda: unpressed_function())
    ui.retForButton.released.connect(lambda: unpressed_function())
    ui.retRevButton.released.connect(lambda: unpressed_function())
    ui.prcEndButton.released.connect(lambda: unpressed_function())
    ui.almOvrButton.released.connect(lambda: unpressed_function())
    ui.almRstButton.released.connect(lambda: unpressed_function())
    ui.lockRstButton.released.connect(lambda: unpressed_function())
    
    ui.laserOnButton.clicked.connect(lambda: laser_on_function())

    sys.exit(app.exec_())
