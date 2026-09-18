/*
  Desk Buddy — Eyes + Clock Firmware
  ----------------------------------
  Board: ESP32
  Display: SSD1306 128x64 OLED (I2C)
  Input: TTP223 touch sensor

  Features:
  1. Animated blinking "eyes" face (idle/default state)
  2. Live time display, synced over Wi-Fi via NTP
  3. Auto mode switching: idles on eyes, a touch shows the
     clock for a few seconds, then returns to eyes automatically

  Libraries needed (Arduino Library Manager):
  - Adafruit GFX Library
  - Adafruit SSD1306
  - (WiFi.h and time.h are built into the ESP32 core)

  Wiring (adjust to match your build):
  - OLED SDA -> GPIO 21
  - OLED SCL -> GPIO 22
  - Touch sensor OUT -> GPIO 4
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <time.h>

// ---------- CONFIG ----------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define TOUCH_PIN 4

const char* WIFI_SSID = "Airtel_Starlight";
const char* WIFI_PASSWORD = "Neverland";

// Set your timezone offset from UTC in seconds (e.g. IST = +5:30 = 19800)
const long GMT_OFFSET_SEC = 19800;
const int DAYLIGHT_OFFSET_SEC = 0;
const char* NTP_SERVER = "pool.ntp.org";

const unsigned long CLOCK_DISPLAY_MS = 5000;   // how long clock stays up after a touch
const unsigned long BLINK_MIN_MS = 2000;       // random blink timing (min)
const unsigned long BLINK_MAX_MS = 5000;       // random blink timing (max)
// -----------------------------

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

enum Mode { EYES, CLOCK };
Mode currentMode = EYES;

unsigned long modeSwitchTime = 0;
unsigned long nextBlinkTime = 0;
bool eyesClosed = false;
bool lastTouchState = LOW;
bool wifiConnected = false;

// ---------- SETUP ----------
void setup() {
  Serial.begin(115200);
  pinMode(TOUCH_PIN, INPUT);

  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true) delay(1000);
  }
  display.clearDisplay();
  display.display();

  connectWiFi();
  scheduleNextBlink();
}

// ---------- MAIN LOOP ----------
void loop() {
  handleTouchInput();

  if (currentMode == CLOCK && millis() - modeSwitchTime > CLOCK_DISPLAY_MS) {
    currentMode = EYES;
  }

  if (currentMode == EYES) {
    drawEyes();
  } else {
    drawClock();
  }

  delay(30); // small delay keeps animation smooth without hammering the CPU
}

// ---------- WIFI + TIME ----------
void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");

  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 10000) {
    delay(300);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    wifiConnected = true;
    Serial.println("\nWiFi connected");
    configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
  } else {
    wifiConnected = false;
    Serial.println("\nWiFi failed — clock mode will show a placeholder");
  }
}

// ---------- TOUCH HANDLING ----------
void handleTouchInput() {
  bool touchState = digitalRead(TOUCH_PIN);

  // rising edge = a fresh touch
  if (touchState == HIGH && lastTouchState == LOW) {
    currentMode = CLOCK;
    modeSwitchTime = millis();
  }
  lastTouchState = touchState;
}

// ---------- EYES ANIMATION ----------
void scheduleNextBlink() {
  unsigned long blinkDelay = random(BLINK_MIN_MS, BLINK_MAX_MS);
  nextBlinkTime = millis() + blinkDelay;
}

void drawEyes() {
  if (millis() > nextBlinkTime) {
    eyesClosed = !eyesClosed;
    // after closing briefly, reopen quickly and schedule the next blink
    if (eyesClosed) {
      nextBlinkTime = millis() + 150; // eyes stay closed ~150ms
    } else {
      scheduleNextBlink();
    }
  }

  display.clearDisplay();

  int leftEyeX = 34;
  int rightEyeX = 94;
  int eyeY = SCREEN_HEIGHT / 2;
  int eyeRadius = 16;

  if (eyesClosed) {
    // draw closed eyes as horizontal lines
    display.fillRoundRect(leftEyeX - eyeRadius, eyeY - 3, eyeRadius * 2, 6, 3, SSD1306_WHITE);
    display.fillRoundRect(rightEyeX - eyeRadius, eyeY - 3, eyeRadius * 2, 6, 3, SSD1306_WHITE);
  } else {
    display.fillCircle(leftEyeX, eyeY, eyeRadius, SSD1306_WHITE);
    display.fillCircle(rightEyeX, eyeY, eyeRadius, SSD1306_WHITE);
  }

  display.display();
}

// ---------- CLOCK DISPLAY ----------
void drawClock() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  struct tm timeInfo;
  char timeStr[9]; // HH:MM:SS

  if (wifiConnected && getLocalTime(&timeInfo)) {
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeInfo);
  } else {
    strcpy(timeStr, "--:--:--");
  }

  display.setTextSize(2);
  int16_t x1, y1;
  uint16_t textWidth, textHeight;
  display.getTextBounds(timeStr, 0, 0, &x1, &y1, &textWidth, &textHeight);
  int centeredX = (SCREEN_WIDTH - textWidth) / 2;
  int centeredY = (SCREEN_HEIGHT - textHeight) / 2;

  display.setCursor(centeredX, centeredY);
  display.print(timeStr);

  display.display();
}
