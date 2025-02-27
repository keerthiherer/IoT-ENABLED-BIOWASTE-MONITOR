import serial
import requests
import time
import re  # Import regex module

# Configure the serial connection
SERIAL_PORT = 'COM3'  # Change as needed
BAUD_RATE = 9600

# Django API URL
DJANGO_API_URL = "http://127.0.0.1:8000/api/iotproject"

# Open Serial Connection
try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=2)
    print("Connected to Arduino on", SERIAL_PORT)
    time.sleep(2)
except Exception as e:
    print("Error connecting to serial:", e)
    exit()

def send_to_django(temperature, humidity, mq2, soil_moisture):
    """ Sends sensor data to Django API """
    payload = {
        "temperature": temperature,
        "humidity": humidity,
        "mq2_value": mq2,
        "soil": str(soil_moisture)
    }
    
    try:
        response = requests.post(DJANGO_API_URL, json=payload)
        print(payload)
        if response.status_code == 200:
            print(f"Data Sent: Temp={temperature}°C, Humidity={humidity}%, MQ-2={mq2}, Soil Moisture={soil_moisture}")
        else:
            print(f"Failed to send data: {response.status_code}, {response.text}")
    except Exception as e:
        print("Error sending data:", e)

while True:
    try:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()  
            print("Received:", line)

            # Use regex to extract numeric values
            numbers = re.findall(r"[-+]?\d*\.\d+|\d+", line)

            if len(numbers) >= 4:  # Ensure we have enough values
                temp = float(numbers[0])
                hum = float(numbers[1])
                mq2 = float(numbers[3])
                soil_moisture = int(numbers[4])

                # Send to Django
                send_to_django(temp, hum, mq2, soil_moisture)

        time.sleep(5)
    except KeyboardInterrupt:
        print("Stopping script...")
        ser.close()
        break
    except Exception as e:
        print("Error:", e)
