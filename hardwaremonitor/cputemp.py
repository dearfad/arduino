import sys
import time
import clr
sys.path.append(r"D:\Github\Repositories\arduino\cpuinfo")
clr.AddReference("OpenHardwareMonitorLib")
from OpenHardwareMonitor.Hardware import Computer
computer = Computer()
computer.CPUEnabled = True
computer.Open()
# print(computer.Hardware[0].Identifier)
# print(computer.Hardware[0].Sensors)

while True:
    for a in range(0, len(computer.Hardware[0].Sensors)):
        # print(a)
#         print(computer.Hardware[0].Sensors[a].Identifier)
        if str(computer.Hardware[0].Sensors[a].Identifier) == "/intelcpu/0/temperature/2":
            print(computer.Hardware[0].Sensors[a].Value)
    computer.Hardware[0].Update()
    time.sleep(1)
#     print("=================")