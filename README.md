#  Smart Pill Box – Arduino

A **Smart Pill Box system** built using **Arduino Uno**, **I2C LCD**, and real-time alarm logic to remind users to take medicines on time.  
The system supports **multiple alarms**, **snooze functionality**, **visual + buzzer alerts**, and an **interactive LCD menu** controlled using buttons.

---

## Features

-  Real-Time Clock functionality (software RTC using `TimeLib`)
-  Up to **4 configurable medicine alarms**
-  Snooze option for reminders
-  20×4 I2C LCD menu system
-  Button-based navigation
-  Buzzer + LED alerts
-  Clear, menu-driven UI for elderly-friendly usage

---

## Hardware Components Used

- Arduino Uno  
- 20×4 I2C LCD (Address: `0x27`)  
- Push Buttons ×5  
- Buzzer  
- LEDs (Red & Green)  
- Resistors (220Ω)  
- Jumper Wires  

---

## Pin Configuration

| Component               | Arduino Pin |
|------------------------|-------------|
| Button 1 (Select)       | D3          |
| Button 2 (Back/Delete)  | D4          |
| Button 3 (Up)           | D5          |
| Button 4 (Down)         | D6          |
| Button 5 (Enter/Snooze) | D7          |
| Buzzer                  | D11         |
| LED 1                   | D10         |
| LED 2                   | D9          |
| LCD (I2C)               | SDA / SCL   |

---

## Circuit Diagram

<img src="https://github.com/user-attachments/assets/29377093-e18d-4f3f-b103-b5d1d5793e9c" width="700"/>

---

## Code Structure Overview

- Multi-page LCD UI system  
- `PageNo` variable controls menu navigation  

### Separate functions for:
- Time setup  
- Alarm creation  
- Alarm deletion  
- Alarm alert screens  

### Additional Logic:
- Snooze handled using minute offset (`SN`)
- Alarm lock implemented using channel flags (`Ch1–Ch4`) to prevent repeated triggers

---

## 📸 Sample Outputs

<p align="center">
  <img src="https://github.com/user-attachments/assets/ae8cd882-7546-43df-a3db-caad2854e108" width="350"/>
  <img src="https://github.com/user-attachments/assets/69b6bf8e-0ccb-47a0-9428-ab06159e82fb" width="350"/>
</p>

---

## 🚀 How to Run

1. Clone the repository  
   ```bash
   git clone https://github.com/your-username/smart-pill-box-arduino


2. Open smart_pill_box.ino in Arduino IDE
3. Install required libraries:
- LiquidCrystal_I2C
- TimeLib
4. Upload the code to Arduino Uno
5. Power the circuit and start configuring alarms 

## Libraries Used
# include <Wire.h>
# include <LiquidCrystal_I2C.h>
# include <TimeLib.h>

##👤 Author

Vaasantha Sri Surya
Computer Science Engineer | Mechatronics Background
Interested in Embedded Systems, Robotics, and AI

🔗 GitHub: https://github.com/Surya7702-VSS

🔗 LinkedIn: https://www.linkedin.com/in/vaasantha-sri-surya-kalidindi-3ba72333a
