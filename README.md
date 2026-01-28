# Smart-Pill-Box-Arduino

A Smart Pill Box system built using Arduino Uno, I2C LCD, and real-time alarm logic to remind users to take medicines on time.
The system supports multiple alarms, snooze, visual + buzzer alerts, and an interactive LCD menu controlled using buttons.

Features:
Real-Time Clock Functionality (software RTC using TimeLib)
Up to 4 configurable medicine alarms
Snooze option for reminders
20×4 I2C LCD menu system
Button-based navigation
Buzzer + LED alerts
Clear, menu-driven UI for elderly-friendly usage

Hardware Components Used:
Arduino Uno
20×4 I2C LCD (Address: 0x27)
Push Buttons ×5
Buzzer
LEDs (Red & Green)
Resistors (220Ω)
Jumper Wires

Pin Configurations:
| Component               | Arduino Pin |
| ----------------------- | ----------- |
| Button 1 (Select)       | D3          |
| Button 2 (Back/Delete)  | D4          |
| Button 3 (Up)           | D5          |
| Button 4 (Down)         | D6          |
| Button 5 (Enter/Snooze) | D7          |
| Buzzer                  | D11         |
| LED 1                   | D10         |
| LED 2                   | D9          |
| LCD (I2C)               | SDA / SCL   |

Code Structure Overview:
Multi-page LCD UI system
PageNo controls menu navigation

Separate functions for:
Time setup
Alarm creation
Alarm deletion
Alarm alert screens
Snooze logic handled using minute offset (SN)
Alarm lock using channel flags (Ch1–Ch4) to prevent repeat triggers

How to Run:
Clone the repository
git clone https://github.com/your-username/smart-pill-box-arduino

Open smart_pill_box.ino in Arduino IDE

Install required libraries:
LiquidCrystal_I2C
TimeLib

Upload the code to Arduino Uno

Power the circuit and start configuring alarms 

Libraries Used
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimeLib.h>



👤 Author

Vaasantha Sri Surya
Computer Science Engineer | Mechatronics Background
Interested in Embedded Systems, Robotics, and AI

🔗 GitHub: https://github.com/Surya7702-VSS
🔗 LinkedIn: www.linkedin.com/in/vaasantha-sri-surya-kalidindi-3ba72333a
