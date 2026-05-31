# Footsteps Power Generation
Generating Power using foot steps

## Overview
The Footsteps Power Generation System is a renewable energy harvesting solution designed to generate electricity from human footsteps using piezoelectric sensors. The system converts mechanical pressure into electrical energy and stores it for later use. It also integrates automation and IoT monitoring using ESP32, an LDR sensor, and Telegram notifications.

## Features
- Footstep-based power generation
- Piezoelectric energy harvesting
- Real-time voltage monitoring
- Automatic street light control using LDR
- Rechargeable battery energy storage
- LCD display for live voltage status
- IoT-based Telegram notifications
- Eco-friendly and low-cost design
## Components Used
- ESP32 Microcontroller
- Piezoelectric Sensors (Piezo Plates)
- Voltage Sensor Module
- LDR Sensor
- 16×2 LCD with I2C Module
- Li-ion Battery
- TP4056 Charging Module
- LED (Street Light)
## Working Principle

The system operates by converting mechanical pressure from human footsteps into electrical energy using piezoelectric sensors.

### Normal Operation
- User steps on piezo plates
- Voltage is generated
- ESP32 measures voltage
- LCD displays voltage in real time
### Energy Storage
- Generated AC voltage is rectified to DC
- TP4056 module charges Li-ion battery
- Energy is stored for future use
### Automatic Lighting
- LDR detects ambient light
- LED turns ON in darkness
- LED turns OFF during daylight
### IoT Monitoring
- ESP32 sends voltage and system status updates
- Telegram bot provides remote monitoring
## Experimental Results
- Footstep Detection----Successful
- Voltage Generation----Successful
- Battery Charging----Successful
- LCD Monitoring----Successful
- LDR Automation----Successful
- Telegram Alerts---Successful
## Applications
- Smart Street Lighting
- Railway Stations
- Shopping Malls
- Airports
- Colleges and Universities
- Smart City Infrastructure
- Public Walkways
- Renewable Energy Projects
## Future enhancement
- Higher efficiency piezoelectric materials
- Cloud-based IoT monitoring
- Mobile application integration
- GPS-based monitoring
- Smart energy analytics
- Large-scale deployment in smart cities
- Supercapacitor-based energy storage
## Technologies used
- Embedded Systems
- ESP32 Programming
- Arduino IDE
- IoT Monitoring
- Renewable Energy Harvesting
- Sensor Integration
- Real-Time Monitoring
## Authors
- Jakkula Sharanya
- Mudavath Sruthi
- Gumpu Shiva Shanker
- R. Bheem Reddy
## Lincense
This project is an academic project developed to explore innovative solutions in renewable energy generation and smart monitoring systems.
