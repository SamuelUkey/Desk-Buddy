<img width="72" height="96" alt="a42338c030af6d9c" src="https://github.com/user-attachments/assets/b4dd6b75-0e49-4cf4-bf2e-70e949cd6731" /> # 🤖 Desk Buddy — ESP32-Based Interactive Desktop Companion

Desk Buddy is a compact interactive desktop companion built around an ESP32.
It responds to touch, blinks animated eyes on an OLED display, shows the
time, and gives sound/voice feedback — designed and built end-to-end,
from circuit and PCB design in KiCad to a 3D-printed enclosure.

![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=flat&logo=arduino&logoColor=white)
![ESP32](https://img.shields.io/badge/-ESP32-E7352C?style=flat&logo=espressif&logoColor=white)
![KiCad](https://img.shields.io/badge/-KiCad-314CB0?style=flat&logo=kicad&logoColor=white)
![C](https://img.shields.io/badge/-C-A8B9CC?style=flat&logo=c&logoColor=white)

---

## 📸 Demo

*(Add a photo or short GIF/video of Desk Buddy running here)*

---

## ✨ Features

- **Animated eyes** on an OLED display with natural, randomized blinking
- **Live clock** synced over Wi-Fi via NTP, shown on touch
- **Touch interaction** via a TTP223 touch sensor — auto-switches between
  eyes and clock, then returns to eyes on its own
- **Physical movement** — servo-driven head and leg motion
- **Sound feedback** via buzzer and DFPlayer Mini with speaker
- **Custom PCB** designed in KiCad (schematic capture, ERC, footprint
  assignment, layout)
- **3D-printable enclosure** sized for a desk

---

## 🧰 Hardware Used

| Component | Purpose |
|---|---|
| ESP32 | Main microcontroller |
| SSD1306 OLED (I2C) | Eyes / clock display |
| TTP223 Touch Sensor | User interaction input |
| WS2812B LEDs | Visual feedback |
| Servo motors | Head & leg movement |
| Buzzer | Simple audio cues |
| DFPlayer Mini + speaker | Voice/sound playback |

---

## 🔌 Circuit & PCB

Designed in KiCad — schematic, ERC-checked, with custom footprints and
PCB layout.

C:/Users/Rick/Downloads/schematic.png

---

## 💻 Firmware

Main firmware: [`DeskBuddy_Eyes_Clock.ino`](./DeskBuddy_Eyes_Clock.ino)

Built with:
- Adafruit GFX Library
- Adafruit SSD1306
- ESP32 WiFi + NTP (built into the ESP32 Arduino core)

### How it works
- Idles on animated blinking eyes by default
- A touch on the sensor switches the display to the current time
  (synced over Wi-Fi), then returns to the eyes automatically after
  a few seconds
- Designed to feel "alive" even with no active interaction

### Flashing it yourself
1. Install the Arduino IDE and the ESP32 board package
2. Install the Adafruit GFX and Adafruit SSD1306 libraries
3. Open `DeskBuddy_Eyes_Clock.ino`, set your Wi-Fi credentials and GMT offset
4. Select your ESP32 board and port, then Upload

---

## 📁 Repo Structure
