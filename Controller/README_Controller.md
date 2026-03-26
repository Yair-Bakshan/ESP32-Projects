# 🕹️ Controller

> Joystick + potentiometer input reader with dead zone filtering and normalized output — ready to plug into any project.

---

## Overview

Reads a 2-axis joystick and a rotary potentiometer, normalizes them into clean float ranges, and streams the values over Serial at ~60 fps. Drop this into any project that needs analog input — robots, games, camera rigs, you name it.

---

## Hardware

| Component | Pin |
|-----------|-----|
| Joystick VRX (X-axis) | `15` |
| Joystick VRY (Y-axis) | `2` |
| Potentiometer | `4` |

> Designed for a **12-bit ADC** (e.g. ESP32). If you're using a standard Arduino (10-bit), change `analogReadResolution(12)` and `4095.0` → `1023.0`.

---

## Output Format

Values are printed to Serial at **115200 baud**, one line per frame (~16 ms):

```
X,Y,Rotation
```

| Channel | Range | Notes |
|---------|-------|-------|
| X | `-1.0` → `1.0` | Center dead zone applied |
| Y | `-1.0` → `1.0` | Up = positive, dead zone applied |
| Rotation | `0.0` → `360.0` | Full potentiometer sweep |

---

## Dead Zone

A ±35% dead zone is applied to both joystick axes so natural thumb drift at rest doesn't cause drift in your application:

```cpp
#define DEAD_ZONE 0.35

if (fabs(value) < DEAD_ZONE) value = 0.0;
```

Adjust this constant to taste — lower for more sensitivity, higher for a firmer snap-to-center.

---

## Usage

1. Wire the joystick and potentiometer to the pins above.
2. Upload the sketch.
3. Open Serial Monitor at **115200 baud** to see live output.
4. Replace the `Serial.print` calls in `loop()` with your own logic:

```cpp
void loop() {
  float x   = getX();    // -1.0 to 1.0
  float y   = getY();    // -1.0 to 1.0
  float rot = getRot();  //  0.0 to 360.0

  // Your code here...
}
```

---

## Customization Ideas

- **Button input** — add a digital read for the joystick's built-in click button
- **Smoothing** — apply a low-pass filter for even silkier output: `smoothX = smoothX * 0.8 + getX() * 0.2`
- **USB HID** — pair with TinyUSB to turn this into a real USB gamepad
- **Wireless** — send values over BLE or ESP-NOW to a receiver board
