import serial

# Open serial connection (change port and baud rate accordingly)
ser = serial.Serial('COM3', 9600, timeout=1)

# Wait for Arduino to initialize
ser.readline()

while True:
    # Read data from Arduino
    if ser.in_waiting > 0:
        data = ser.readline().decode().strip()
        print("Received data from Arduino:", data)