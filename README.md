## Smart Garden System - README

### Project Overview
The Smart Garden System is an automated solution to help maintain the health and hydration of your garden. It uses an Arduino microcontroller to monitor soil moisture and control a water pump based on the detected moisture levels. Optional features include monitoring temperature, humidity, and light levels.

### Components
1. **Arduino Board** (e.g., Arduino Uno)
2. **Soil Moisture Sensor**
3. **Relay Module**
4. **Water Pump**
5. **DHT11/DHT22 Temperature and Humidity Sensor** (optional)
6. **Light Sensor** (optional)
7. **Jumper Wires**
8. **Breadboard** (optional)

### Circuit Diagram
#### Basic Setup
1. **Soil Moisture Sensor**:
   - VCC to 5V
   - GND to GND
   - Data Pin to A0

2. **Relay Module**:
   - VCC to 5V
   - GND to GND
   - Control Pin to Digital Pin 8
   - Connect the water pump to the relay module

#### Optional Components
3. **DHT11/DHT22 Sensor**:
   - VCC to 5V
   - GND to GND
   - Data Pin to Digital Pin 2

4. **Light Sensor**:
   - VCC to 5V
   - GND to GND
   - Data Pin to A1

### Installation and Setup
1. **Arduino IDE**: Download and install the Arduino IDE from [here](https://www.arduino.cc/en/software).
2. **Libraries**: Install the DHT sensor library. Go to `Sketch` > `Include Library` > `Manage Libraries`, and search for `DHT sensor library`. Install the library by Adafruit.

### Code
Upload the provided code to your Arduino board:

```cpp
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
```

### Usage
1. Connect the components as per the circuit diagram.
2. Upload the provided code to your Arduino board.
3. Open the Serial Monitor from the Arduino IDE to observe the sensor readings and the state of the water pump.
4. Adjust the soil moisture threshold in the code to match your soil moisture sensor's characteristics.

### Calibration
- Test the soil moisture sensor in dry and wet soil to determine appropriate threshold values.
- Ensure the DHT sensor is placed in a location that accurately represents the garden environment.
- Place the light sensor in an area that receives adequate light to measure the ambient light levels effectively.

### Maintenance
- Regularly check and clean the sensors for accurate readings.
- Ensure the water pump and relay module are functioning correctly and replace them if necessary.
- Monitor the power supply to avoid any interruptions.

### Troubleshooting
- **No readings in Serial Monitor**: Check all connections and ensure the Arduino is properly connected to your computer.
- **Water pump not turning on/off**: Verify the relay module's connections and the threshold value in the code.
- **Inaccurate sensor readings**: Recalibrate the sensors and ensure they are placed correctly in the garden.


### Contributions
Feel free to contribute to this project by submitting issues or pull requests on the project's GitHub repository.

