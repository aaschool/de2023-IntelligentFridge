#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Create an instance of the BME280 sensor
Adafruit_BME280 bme;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  Serial.println("BME280 Sensor");

  // Initialize the BME280 sensor
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  // Read temperature, pressure, and humidity from the BME280 sensor
  float temperature = bme.readTemperature();
  float pressure = bme.readPressure() / 100.0F;
  float humidity = bme.readHumidity();

  // Print the sensor values to the serial monitor
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  // Wait for 2 seconds before taking the next reading
  delay(2000);
}