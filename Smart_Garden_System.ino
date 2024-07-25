#include <DHT.h>

// Constants
#define SOIL_MOISTURE_PIN A0
#define RELAY_PIN 8
#define DHT_PIN 2
#define DHT_TYPE DHT11 // Change to DHT22 if using that sensor
#define LIGHT_SENSOR_PIN A1

// Thresholds
#define SOIL_MOISTURE_THRESHOLD 500 // Adjust this value based on your soil moisture sensor

// DHT Sensor
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);

  // Initialize pins
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  // Read soil moisture
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);

  // Control water pump
  if (soilMoistureValue < SOIL_MOISTURE_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH); // Turn on pump
    Serial.println("Pump ON");
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off pump
    Serial.println("Pump OFF");
  }

  // (Optional) Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // (Optional) Read light level
  int lightLevel = analogRead(LIGHT_SENSOR_PIN);
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  // Wait before next reading
  delay(2000); // Adjust delay as needed
}
