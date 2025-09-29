# Soccer Bot / 2WD RC Car

![](https://img.shields.io/badge/Arduino%20-IDE-458b8f?style=for-the-badge&labelColor=grey&logo=arduino&logoColor=%2362AEB2&logoSize=auto&link=https%3A%2F%2Fdocs.arduino.cc%2Fprogramming%2F&link=https%3A%2F%2Fwww.arduino.cc%2Fen%2Fsoftware%2F)
![](https://img.shields.io/badge/Devkit-ESP32-red?style=for-the-badge&labelColor=grey&logo=espressif&logoColor=ca2f11&logoSize=auto&link=https%3A%2F%2Fwww.espressif.com%2Fen%2Fproducts%2Fdevkits&link=https%3A%2F%2Flastminuteengineers.com%2Fgetting-started-with-esp32%2F)
![](https://img.shields.io/badge/Devkit-ESP8266-692f26?style=for-the-badge&labelColor=grey&logo=espressif&logoColor=ca2f11&logoSize=auto&link=https%3A%2F%2Fwww.espressif.com%2Fsites%2Fdefault%2Ffiles%2Fdocumentation%2FESP8266-DevKitS_user_guide__EN.pdf&link=https%3A%2F%2Flastminuteengineers.com%2Fgetting-started-with-esp8266)
![](https://img.shields.io/badge/ESP%20NOW-Protocol-yellow?style=for-the-badge&labelColor=grey&logo=espressif&logoColor=ca2f11&logoSize=auto&link=https%3A%2F%2Fdocs.espressif.com%2Fprojects%2Fesp-idf%2Fen%2Fstable%2Fesp32%2Fapi-reference%2Fnetwork%2Fesp_now.html&link=https%3A%2F%2Fdocs.arduino.cc%2Ftutorials%2Fnano-esp32%2Fesp-now%2F)
![](https://img.shields.io/badge/C%2B%2B-Commands-blue?style=for-the-badge&labelColor=grey&logo=cplusplus&logoColor=blue&logoSize=auto&link=https%3A%2F%2Fdocs.arduino.cc%2Fprogramming%2F&link=https%3A%2F%2Fdocs.arduino.cc%2Fprogramming%2F)

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
  - L293D / L298n / IBT-2 motor driver  
  - N20 / 25GA / 37GB 550 DC motors (2-wheel / 4-wheel drive)  
  - 12V Li-ion battery  

*See the `docs/` folder for hardware setup images, pinouts and block diagram (JPG).*  

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

![Soccer_Bot_Block diagram](https://github.com/user-attachments/assets/29635832-dcfb-4e8a-8aa4-a08110ba8425)

---

## License

This project is licensed under the **MIT License** – see [LICENSE](LICENSE.md) for details.  

---

## Acknowledgements

- [ESP-NOW Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/network/esp_now.html)  
- Arduino core for ESP32 & ESP8266  
