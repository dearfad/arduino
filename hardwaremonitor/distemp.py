import serial
port = "COM3"
bps = 115200
timeout = None
arduino_serial = serial.Serial(port, bps, timeout=timeout)
arduino_serial.write("38")