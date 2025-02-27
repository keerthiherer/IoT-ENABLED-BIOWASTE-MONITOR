#include <DHT.h>

// Define pins
#define DHTPIN 2          // DHT11 Data pin connected to digital pin 2
#define DHTTYPE DHT11     // Define the type of DHT sensor
#define GAS_SENSOR_PIN A0 // Gas sensor connected to analog pin A0

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

void setup() {
    Serial.begin(9600);  // Start serial communication
    dht.begin();         // Initialize the DHT sensor
}

void loop() {
    // Read temperature and humidity from DHT11
    float temperature = dht.readTemperature(); // Read temperature in Celsius
    float humidity = dht.readHumidity();       // Read humidity

    // Read gas sensor value
    int gasLevel = analogRead(GAS_SENSOR_PIN);

    // Check if reading failed
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
    } else {
        // Print values to Serial Monitor
        Serial.println("====================");
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");

        Serial.print("Gas Level: ");
        Serial.println(gasLevel);

        Serial.println("====================\n");
    }

    delay(10000); // Wait for 10 seconds before the next reading
}
