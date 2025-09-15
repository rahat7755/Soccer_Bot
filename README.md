# Soccer Bot / 2WD RC Car

![Arduino](https://img.shields.io/badge/Arduino-IDE-blue)
![ESP32](https://img.shields.io/badge/Board-ESP32-green)
![ESP8266](https://img.shields.io/badge/Board-ESP8266-orange)
![ESP-NOW](https://img.shields.io/badge/Protocol-ESP--NOW-red)
![C++](https://img.shields.io/badge/Language-C++-lightgrey)

A two-wheel drive Soccer Bot controlled wirelessly using **ESP32** (remote) and **ESP8266** (receiver).  
The system uses **ESP-NOW** protocol for reliable, low-latency communication.  
This repository includes firmware for the remote, the receiver, and a utility to check the ESP8266 MAC address.

---

## Repository Contents

- `Remote/` → ESP32 code for remote control (joystick/buttons input → wireless transmission)  
- `Receiver/` → ESP8266 code for motor driver control (PWM output to motors)  
- `Get_MAC/` → ESP8266 utility code to fetch and print the MAC address  

---

## Features

- **ESP32 Remote**  
  - Reads input from joystick 
  - Transmits commands via ESP-NOW  
  - Simple and responsive control  

- **ESP8266 Receiver**  
  - Receives commands wirelessly  
  - Controls motor driver (PWM output for 2WD movement)  
  - Supports emergency stop  

- **Utility**  
  - Quick script to print the ESP8266’s MAC address (required for pairing with ESP32 remote)  

---

## Communication

- **Protocol**: ESP-NOW  
- **Latency**: ~<10 ms (suitable for real-time control)  
- **Range**: ~50–100m (depending on environment)  

---

## Hardware Setup

- **Remote (ESP32):**  
  - ESP32 Dev Module  
  - Joystick + buttons  
  - Powered by Li-ion / USB  

- **Receiver (ESP8266):**  
  - ESP8266 NodeMCU  
  - L293D / IBT-2 motor driver  
  - N20 / 25GA / 37GB 550 DC motors (2-wheel / 4-wheel drive)  
  - 12V Li-ion battery  

*See the `docs/` folder for hardware setup images and block diagram (JPG).*  

---

## Setup Guide

1. **Get the ESP8266 MAC address**  
   - Flash `Get_MAC` to ESP8266  
   - Open Serial Monitor → copy the MAC address  

2. **Configure Remote (ESP32)**  
   - Paste ESP8266 MAC address in the remote code  
   - Flash `Remote` to ESP32  

3. **Flash Receiver (ESP8266)**  
   - Upload `Receiver` code to ESP8266  

4. **Power up both boards**  
   - ESP32 → Remote controller  
   - ESP8266 → Robot base (connected to motor driver)  

5. **Test Movement**  
   - Use joystick/buttons → robot moves accordingly  

---

## Block Diagram

Add a diagram (e.g. `docs/block_diagram.jpg`) showing the connection between:  
**ESP32 (Remote) → ESP-NOW → ESP8266 (Receiver) → Motor Driver → Motors**  

---

## License

This project is licensed under the **MIT License** – see [LICENSE](LICENSE) for details.  

---

## Acknowledgements

- [ESP-NOW Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/network/esp_now.html)  
- Arduino core for ESP32 & ESP8266  
