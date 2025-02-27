#include <SPI.h>
#include <LoRa.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// LoRa pins
#define SS 10
#define RST 9
#define DIO0 2

// GPS setup (use SoftwareSerial for GPS module)
SoftwareSerial gpsSerial(4, 3); // RX, TX for GPS
TinyGPSPlus gps;

// Variables for data transmission
String lastRFID = "ls";  // Default RFID value
String gpsData = "nv";   // Default GPS value
unsigned long lastGPSTime = 0; // Timer for GPS updates
const unsigned long gpsInterval = 10000; // 10 seconds interval

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  while (!Serial);

  // Initialize GPS
  gpsSerial.begin(9600);

  // Initialize LoRa
  Serial.println("Initializing LoRa...");
  if (!LoRa.begin(433E6)) { // Set frequency to 433 MHz
    Serial.println("LoRa initialization failed!");
    while (1);
  }
  Serial.println("LoRa Initialized.");
}

void loop() {
  // Read RFID data from Serial
  if (Serial.available()) {
    String newRFID = Serial.readStringUntil('\n'); // Read the string
    newRFID.trim(); // Remove leading and trailing whitespace
    if (newRFID.length() > 0) { // Validate RFID data
      lastRFID = newRFID;
      Serial.print("Updated RFID: ");
      Serial.println(lastRFID);

      // Send updated RFID data immediately
      sendLoRaData(lastRFID, gpsData);
    }
  }

  // Update GPS data at intervals
  if (millis() - lastGPSTime >= gpsInterval) {
    updateGPSData();
    sendLoRaData(lastRFID, gpsData); // Send updated data
    lastGPSTime = millis();
  }
}

// Function to update GPS data
void updateGPSData() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated()) {
    gpsData = String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
    Serial.print("Updated GPS: ");
    Serial.println(gpsData);
  } else {
    gpsData = "nv"; // No GPS data available
    Serial.println("GPS not available.");
  }
}

// Function to send data via LoRa
void sendLoRaData(String rfid, String gps) {
  
  if (!gpsData.equals("nv") && 
    !rfid.equals("$GPTXT,01,01,01,NMEA unknown msg*58") && 
    !rfid.equals("$GPGGA,140403.00,,,,,0,00,99.99,,,,,,*64")) {
    
    // Construct the message
    String message = "RFID:" + rfid + ",GPS:" + gpsData;

    // Debugging message
    Serial.print("Sending LoRa Data: ");
    Serial.println(message);

    // Send data via LoRa
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
}

}
