# Industrial Safety Monitoring System

A basic embedded systems project developed using the **ESP8266 NodeMCU** to monitor industrial safety parameters such as temperature, humidity, gas leakage, and motion. The system displays real-time sensor data on an I2C LCD and activates a buzzer whenever unsafe conditions are detected.

## Features

- 🌡️ Temperature monitoring (DHT11)
- 💧 Humidity monitoring
- 🔥 Gas leak detection (MQ-9)
- 📈 Motion/Impact detection (MPU6050)
- 📟 16×2 I2C LCD status display
- 🔔 Buzzer alert system
- 💻 Serial Monitor logging

## Components

- ESP8266 NodeMCU
- DHT11 Temperature & Humidity Sensor
- MQ-9 Gas Sensor
- MPU6050 Accelerometer & Gyroscope
- 16×2 I2C LCD
- Active Buzzer
- Breadboard & Jumper Wires

## Pin Connections

| Component | ESP8266 Pin |
|-----------|-------------|
| DHT11 Data | D2 (GPIO4) |
| MQ-9 Analog Output | A0 |
| Buzzer | D5 (GPIO14) |
| MPU6050 SDA | D2 (GPIO4) |
| MPU6050 SCL | D1 (GPIO5) |
| I2C LCD SDA | D2 (GPIO4) |
| I2C LCD SCL | D1 (GPIO5) |

> **Note:** The MPU6050 and I2C LCD share the same I2C bus (SDA and SCL).

## Working

The ESP8266 continuously reads temperature, humidity, gas concentration, and motion data from the connected sensors. If any sensor reading exceeds its predefined threshold, the buzzer is activated and an alert message is displayed on the LCD. When all sensor readings remain within the safe range, the system displays **"SYSTEM SAFE"**.

## Images

### Hardware Setup

![Project](project.jpg)

### Circuit Diagram

![Circuit Diagram](circuit_diagram.png)

## Future Improvements

- Wi-Fi dashboard for remote monitoring
- Firebase or MQTT integration
- Email or Telegram alerts
- Cloud data logging
- Mobile application support

## Author

**Mitesh Gorad**

Embedded Systems • IoT • Electronics
