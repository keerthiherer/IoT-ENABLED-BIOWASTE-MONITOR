# IoT-Based Plastic Degradation & Methane Utilization

## Project Overview
This project focuses on using **BIO DEGRADING PROCESS** to degrade BIO waste while simultaneously capturing **methane gas**, which is utilized in **biofuel cells**. The system integrates **IoT sensors (MQ-6 Gas Sensor, DHT11 Temperature & Humidity Sensor, and ESP CAM)** to monitor the process in real-time. Data is uploaded to **ThingSpeak** and processed using **Django REST framework** for analysis and optimization.

---

## Features
✅ **Methane Gas Utilization** for biofuel cell energy conversion  
✅ **IoT-Based Real-Time Monitoring** via sensors and cloud integration  
✅ **Data Analytics & Visualization** using Django REST framework & ThingSpeak  
✅ **Scalable & Sustainable** for industrial waste management  

---

## Components & Connections

| **Component**  | **Function**  | **Arduino Connection**  |
|---------------|--------------|-------------------------|
| **Arduino UNO** | Main microcontroller | N/A  |
| **MQ-6 Gas Sensor** | Detects methane emissions | VCC → 5V, GND → GND, A0 → A0 |
| **DHT11 Sensor** | Monitors temperature & humidity | VCC → 5V, GND → GND, Data → D2 |
| **ESP CAM** | Captures real-time images | VCC → 3.3V, GND → GND, TX → RX, RX → TX |
| **ThingSpeak** | Cloud platform for data visualization | Connected via ESP32 WiFi |
| **Django REST Framework** | Backend processing for data analytics | Connected via API |

---

## Working Process
 
1. **Methanogenic bacteria convert these compounds into methane gas.**  
2. **MQ-6 Sensor detects methane concentration for gas measurement.**  
3. **DHT11 Sensor monitors temperature & humidity for optimal bacterial growth.**  
4. **ESP CAM captures real-time images of plastic degradation for visual tracking.**  
5. **Data is uploaded to ThingSpeak and analyzed using Django REST framework.**  
6. **Methane is purified and used in a biofuel cell to generate renewable energy.**  

---

## Installation & Setup
### **Hardware Setup**
1. Connect **MQ-6 Gas Sensor, DHT11 Sensor, and ESP CAM** to Arduino as per the pin configuration table.
2. Ensure **WiFi connectivity** for ESP32 to send data to ThingSpeak.

### **Software Setup**
1. Install **Arduino IDE** and required libraries for **MQ-6, DHT11, and ESP CAM**.
2. Set up **ThingSpeak** account and API keys for cloud data logging.
3. Install **Python, Django REST framework**, and required dependencies:
   ```bash
   pip install django djangorestframework requests
   ```
4. Run the backend server:
   ```bash
   python manage.py runserver
   ```

---

## Applications & Benefits

- **Generates renewable energy** by capturing and utilizing methane gas.
- **Enables real-time monitoring** for optimized biodegradation.
- **Scalable for industrial waste management** and renewable energy production.

---

## Future Enhancements
🔹 **AI-based Optimization** – Using ML models to predict and enhance plastic breakdown rates.  
🔹 **Blockchain Integration** – Secure tracking of waste management and energy output.  

---

## Contributors
- **Keerthibalan** - Project Developer
- [Your Team Members' Names]

---

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Contact
For queries or contributions, contact [Your Email] or visit [Your GitHub Profile](https://github.com/yourusername).

