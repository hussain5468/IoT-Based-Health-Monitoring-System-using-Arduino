# IoT-Based-Health-Monitoring-System-using-Arduino
## Abstract
The IoT-based health monitoring system is an innovative solution aimed at remotely tracking patient vitals such as heart rate and body temperature using Arduino and IoT technologies. The data collected is transmitted wirelessly via the ESP8266 WiFi module and displayed on a cloud platform like ThingSpeak or Blynk. This system allows healthcare professionals to monitor patient health in real-time, improving response times and reducing the burden on hospitals.

## Introduction
Healthcare monitoring is critical in today’s fast-paced world. This project presents a cost-effective and real-time health monitoring solution using Arduino and IoT. It leverages sensors to measure vital parameters and uploads the data to an IoT platform for continuous monitoring.

## Components Required
- Arduino UNO  
- Heartbeat Sensor (Pulse Sensor)  
- Temperature Sensor (LM35 or DHT11)  
- ESP8266 WiFi Module (ESP-01)  
- LCD Display (16x2) with I2C module  
- Breadboard and Jumper Wires  
- Power Supply  

## Block Diagram Description
The system comprises sensors connected to the Arduino UNO, which reads and processes the data. The data is displayed locally on an LCD and also transmitted via the ESP8266 module to an online IoT platform.

## Circuit Description
- The heartbeat sensor is connected to analog pin A0 of the Arduino.  
- The LM35/DHT11 temperature sensor is connected to another analog/digital pin.  
- The ESP8266 is connected via the serial interface (TX/RX).  
- The LCD display is connected using I2C interface for efficient data display.

## Working Principle
The Arduino reads analog values from the heartbeat and temperature sensors, processes them, and sends the data via the ESP8266 WiFi module. The data is uploaded to a cloud platform like ThingSpeak or Blynk, allowing doctors to view it remotely.

## Sample Arduino Code Snippet
```cpp
// Reading temperature from DHT11
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  Serial.println(temp);
  delay(2000);
}

