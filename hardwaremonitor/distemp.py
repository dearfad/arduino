import sys
import time
import clr
import serial

# Use OpenHardwareMonitorLib
sys.path.append(sys.argv[0])
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
    # EasyShield Board Digital ab -> ba
    a = cputemp//10
    b = cputemp%10
    cputemp = str(b)+str(a)
    arduino_serial.write(cputemp.encode("utf-8"))
    computer.Hardware[0].Update()
    time.sleep(1)
