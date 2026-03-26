# 💡 Button Light

> A minimalist sketch that toggles an LED on button press — the classic "Hello, World!" of hardware.

---

## Overview

Press a button, light up an LED. Simple as that. The sketch uses the internal pull-up resistor so no external resistor is needed on the button side, and inverts the logic so the LED turns **on** when the button is held down.

---

## Hardware

| Component | Pin |
|-----------|-----|
| Push Button | `4` (INPUT_PULLUP) |
| LED | `5` (OUTPUT) |

> **Note:** Because `INPUT_PULLUP` is used, the button should connect pin `4` to **GND** when pressed (active-low). No external pull-down resistor needed.

---

## How It Works

```
Button Released → Pin 4 reads HIGH → LED is OFF
Button Pressed  → Pin 4 reads LOW  → LED is ON
```

The logic is inverted in a single line:
```cpp
int useCase = buttonState == LOW ? HIGH : LOW;
```

---

## Pin Diagram

```
Pin 5 ──── [LED] ──── [220Ω]──── GND
Pin 4 ──── [Button] ──── [GND]
```

---

## Usage

1. Wire up the LED and button as described above.
2. Upload the sketch.
3. Press the button — the LED lights up instantly.

---

## Customization Ideas

- **Toggle mode** — flip a boolean on press instead of reading live state
- **Debounce** — add a small `delay()` or use the `Bounce2` library for cleaner input
- **Multiple LEDs** — extend the pattern to light up different LEDs with different buttons
