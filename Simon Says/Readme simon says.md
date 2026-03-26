# 🔴🟡🟢 Simon Says

> The classic memory game — light up a sequence, repeat it back, don't mess up.

---

## Overview

A full implementation of **Simon Says** on Arduino. The game shows an ever-growing sequence of lit LEDs paired with distinct tones, and you must repeat it back in order. Each successful round speeds the sequence up. Miss a step or run out of time — all LEDs flash and you start over.

---

## Hardware

| Component | Pins |
|-----------|------|
| LEDs (×3) | `5`, `18`, `19` |
| Buttons (×3) | `21`, `22`, `23` (INPUT_PULLUP) |
| Passive Buzzer | `4` |

Each button corresponds to the LED at the same index. Button on pin `21` → LED on pin `5`, and so on.

---

## Tones

Each button/LED pair has its own pitch:

| Index | LED Pin | Button Pin | Frequency |
|-------|---------|------------|-----------|
| 0     | 5       | 21         | 329 Hz (E4) |
| 1     | 18      | 22         | 261 Hz (C4) |
| 2     | 19      | 23         | 392 Hz (G4) |

---

## Game Loop

```
SHOW_SEQUENCE
  └─ Adds one random step to the sequence
  └─ Plays each step with light + tone
  └─ → PLAYER_INPUT

PLAYER_INPUT
  └─ Waits for button presses
  └─ Correct press → advance; finish round → speed up → SHOW_SEQUENCE
  └─ Wrong press or timeout (7.5s) → GAME_OVER

GAME_OVER
  └─ All LEDs flash
  └─ Sequence resets, speed resets
  └─ → SHOW_SEQUENCE (new game)
```

---

## Difficulty Progression

The display delay starts at **400 ms** and decreases by **20 ms** each successful round:

```cpp
displayDelay -= 20;  // Gets faster every round
```

By round 20 the sequences are flying at 0 ms delay — good luck.

---

## Input Details

- **Debounce:** 50 ms minimum between accepted presses
- **Timeout:** 7.5 seconds of inactivity during input triggers Game Over
- **Feedback:** Each button press lights the corresponding LED and plays its tone

---

## Pin Diagram

```
Pin 5  ──── [LED 0] ──── [220Ω] ──── GND
Pin 18 ──── [LED 1] ──── [220Ω] ──── GND
Pin 19 ──── [LED 2] ──── [220Ω] ──── GND

Pin 21 ──── [Button 0] ──── GND
Pin 22 ──── [Button 1] ──── GND
Pin 23 ──── [Button 2] ──── GND

Pin 4  ──── [Buzzer +] ──── GND
```

---

## Usage

1. Wire up the LEDs, buttons, and buzzer.
2. Upload the sketch.
3. Watch the first sequence — then repeat it!
4. Keep going as long as you can.

---

## Customization Ideas

- **4th button/LED** — extend the arrays to `4` elements for the classic 4-color Simon experience
- **High score** — track the longest sequence reached and display it on an OLED after Game Over
- **Serial output** — print the sequence to Serial for debugging or logging
- **Difficulty modes** — choose starting speed with a potentiometer before the game begins