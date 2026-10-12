# Controller

Reads a two-axis joystick and a rotary potentiometer, normalizes the values and streams them over Serial. Use it as the input layer for a game, a robot or a camera rig.

## Hardware

| Component | Pin |
|---|---|
| Joystick VRX (X axis) | GPIO 15 |
| Joystick VRY (Y axis) | GPIO 2 |
| Potentiometer | GPIO 4 |

The sketch assumes a 12-bit ADC (0 to 4095), which is the ESP32 default.

## Output

The sketch prints one line per frame (about every 16 ms) at 115200 baud:

```
X,Y,Rotation
```

| Channel | Range | Notes |
|---|---|---|
| X | -1.0 to 1.0 | Dead zone applied |
| Y | -1.0 to 1.0 | Dead zone applied. The direction depends on how the joystick is mounted. |
| Rotation | 0.0 to 360.0 | Full potentiometer sweep |

## Dead Zone

A dead zone of 0.35 is applied to both joystick axes. Small movements around the center read as 0, so a resting thumb does not cause drift.

```cpp
#define DEAD_ZONE 0.35
```

Lower the value for more sensitivity. Raise it for a firmer center.

## Usage

1. Wire the joystick and the potentiometer to the pins above.
2. Upload `Controller.ino`.
3. Open the Serial Monitor at **115200 baud**.
4. Replace the `Serial.print` calls in `loop()` with your own logic:

```cpp
void loop() {
  float x   = getX();    // -1.0 to 1.0
  float y   = getY();    // -1.0 to 1.0
  float rot = getRot();  //  0.0 to 360.0

  // Your code here
}
```

## Notes

All three pins are ADC2 pins. The ESP32 cannot read ADC2 while Wi-Fi is on. If you add Wi-Fi or ESP-NOW, move the inputs to ADC1 pins (GPIO 32 to 39).

## Ideas

- **Button input:** read the click button built into most joystick modules.
- **Smoothing:** add a low-pass filter, for example `smoothX = smoothX * 0.8 + getX() * 0.2`.
- **USB gamepad:** use a board with native USB and a HID library.
- **Wireless:** send the values over Bluetooth LE to a receiver.
