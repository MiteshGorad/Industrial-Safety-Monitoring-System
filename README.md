# Industrial Safety Monitoring System

A basic embedded systems project developed using Arduino Uno to monitor industrial safety parameters such as temperature, humidity, gas leakage, and motion.

## Features

- Temperature monitoring (DHT11)
- Humidity monitoring
- Gas leak detection (MQ-9)
- Motion detection (MPU6050)
- LCD status display
- Buzzer alarm

## Components

- Arduino Uno
- DHT11
- MQ-9 Gas Sensor
- MPU6050
- 16x2 I2C LCD
- Active Buzzer

## Pin Connections

| Component | Pin |
|----------|-----|
| DHT11 | D2 |
| MQ-9 | A0 |
| Buzzer | D6 |
| MPU6050 | I2C |
| LCD | I2C |

## Working

The Arduino continuously reads all sensor values. If any parameter exceeds its predefined threshold, the buzzer is activated and an alert is displayed on the LCD. Otherwise, the system indicates a safe condition.

## Images

### Hardware Setup

![Project](project.jpg)

### Circuit Diagram

![Circuit](circuit_diagram.png)

## Author

Mitesh Gorad
