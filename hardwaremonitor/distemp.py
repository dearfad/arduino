import sys
import time
import clr
import serial

# Use OpenHardwareMonitorLib
sys.path.append(r"D:\Github\Repositories\arduino\cpuinfo")
clr.AddReference("OpenHardwareMonitorLib")
from OpenHardwareMonitor.Hardware import Computer
computer = Computer()
computer.CPUEnabled = True
computer.Open()

# Get Serial Port Ready
port = "COM3"
bps = 9600
timeout = None
arduino_serial = serial.Serial(port, bps, timeout=timeout)

while True:
    cputemp = int(computer.Hardware[0].Sensors[9].Value)
    print(cputemp)
    arduino_serial.write(cputemp)
    computer.Hardware[0].Update()
    time.sleep(1)
