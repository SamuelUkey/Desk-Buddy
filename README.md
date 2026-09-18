<img width="72" height="96" alt="a42338c030af6d9c" src="https://github.com/user-attachments/assets/b4dd6b75-0e49-4cf4-bf2e-70e949cd6731" /># 🤖 Desk Buddy — ESP32-Based Interactive Desktop Companion

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

https://cdn.discordapp.com/attachments/1550522394534482052/1550522512901799978/schematic.png?ex=6aaea41e&is=6aad529e&hm=8e788732a320d308c4cb7ee7978680a0c91277c39238f2063b3997e37a9eb804&
![Uploading a42<svg fill="none" height="96" viewBox="0 0 72 96" width="72" xmlns="http://www.w3.org/2000/svg"><path d="m72 29.3v60.3c0 2.24 0 3.36-.44 4.22-.38.74-1 1.36-1.74 1.74-.86.44-1.98.44-4.22.44h-59.2c-2.24 0-3.36 0-4.22-.44-.74-.38-1.36-1-1.74-1.74-.44-.86-.44-1.98-.44-4.22v-83.2c0-2.24 0-3.36.44-4.22.38-.74 1-1.36 1.74-1.74.86-.44 1.98-.44 4.22-.44h36.3c1.96 0 2.94 0 3.86.22.5.12.98.28 1.44.5v16.88c0 2.24 0 3.36.44 4.22.38.74 1 1.36 1.74 1.74.86.44 1.98.44 4.22.44h16.88c.22.46.38.94.5 1.44.22.92.22 1.9.22 3.86z" fill="#d3d6fd"/><path d="m68.26 20.26c1.38 1.38 2.06 2.06 2.56 2.88.18.28.32.56.46.86h-16.88c-2.24 0-3.36 0-4.22-.44-.74-.38-1.36-1-1.74-1.74-.44-.86-.44-1.98-.44-4.22v-16.880029c.3.14.58.28.86.459999.82.5 1.5 1.18 2.88 2.56z" fill="#939bf9"/><path d="m56.1014 65.0909c-3.1394-3.2-11.7-1.8909-13.7625-1.6545-2.2633-2.2182-4.1981-4.7273-5.7861-7.4546 1.1317-3.1636 1.7705-6.4727 1.9348-9.8182 0-2.9636-1.2047-6.1636-4.5815-6.1636-1.1864.0364-2.2815.6545-2.9021 1.6545-1.442 2.491-.8397 7.4546 1.4419 12.5455-1.5697 4.6545-3.5592 9.1636-5.9138 13.4909-3.5046 1.4182-10.8604 4.7273-11.4627 8.2909-.2373 1.0909.146 2.2.9674 2.9637.8578.6909 1.9165 1.0545 3.0299 1.0545 4.4719 0 8.8161-6.0364 11.8278-11.1273 3.4315-1.1454 6.936-2.0545 10.4952-2.7272 4.7092 4.0181 8.8161 4.6181 10.9882 4.6181 2.9021 0 3.9791-1.1818 4.3441-2.2545.5293-1.1455.2921-2.5091-.6206-3.4182zm-3.0117 2.0182c-.1277.8364-1.2047 1.6545-3.1394 1.1818-2.2451-.5818-4.3442-1.6364-6.1512-3.0727 1.5697-.2364 5.0743-.6 7.5931-.1273.9674.2364 1.9348.8182 1.6975 2.0182zm-20.1509-24.3818c.2007-.3455.5658-.5637.9673-.6 1.077 0 1.3325 1.3091 1.3325 2.3636-.1278 2.5091-.6023 4.9636-1.442 7.3455-1.8252-4.7273-1.4602-8.0546-.8578-9.1091zm-.2373 22.9454c1.0404-2.1636 1.9713-4.3636 2.7744-6.6182 1.1134 1.7455 2.4093 3.3637 3.8695 4.8546-.0182.1091-3.76.8182-6.6439 1.7636zm-7.1186 4.7455c-2.7744 4.4909-5.6766 7.3454-7.2463 7.3454-.2555-.0181-.5111-.1091-.7301-.2363-.3651-.2364-.5111-.6728-.3651-1.0728.3651-1.6545 3.5046-3.909 8.3415-6.0363z" fill="#5865f2"/></svg>338c030af6d9c.svg…]()

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
