# 🎵 Für Elise — Buzzer Edition

> Beethoven's most iconic melody, squeezed into an Arduino and blasted through a passive buzzer. All 1,000+ notes of it.

---

## Overview

This sketch plays a near-complete arrangement of **Für Elise (Op. 173a)** by Ludwig van Beethoven using `tone()` on a passive piezo buzzer. The full melody and its note durations are stored as two large integer arrays, and the sketch iterates through them once on startup.

No loop. One performance. Pure drama.

---

## Hardware

| Component | Pin |
|-----------|-----|
| Passive Piezo Buzzer | `5` |

> **Passive** buzzer required — an active buzzer plays only a fixed tone and won't work here. The built-in LED on pin 5 may also flicker in sync with the melody as a bonus visual.

---

## How It Works

```cpp
tone(PIN_5, melody[i], durations[i]);
delay(durations[i] * 1.3);
```

Each note is played with `tone()` for its specified duration, followed by a `delay` of 1.3× that duration to provide a natural gap between notes (the "articulation" gap). This ratio keeps the melody feeling musical rather than mechanical.

---

## Stats

| Property | Value |
|----------|-------|
| Note count | ~1,000+ |
| Frequency range | ~55 Hz → 2637 Hz |
| Playback | Once, on `setup()` |
| Loop function | Empty — nothing repeats |

---

## Pin Diagram

```
Pin 5 ──── [Buzzer +]
GND   ──── [Buzzer −]
```

No resistor is strictly required for a piezo buzzer, but a 100Ω resistor in series is good practice to protect the output pin.

---

## Usage

1. Connect a passive piezo buzzer between pin `5` and `GND`.
2. Upload the sketch.
3. The melody starts playing immediately after upload.
4. Sit back and enjoy Beethoven.

---

## Customization Ideas

- **Repeat** — move the playback loop into `loop()` for continuous performance
- **Tempo control** — multiply `durations[i]` by a global `tempo` float to speed up or slow down
- **Trigger** — add a button check before playback so it only plays on demand
- **Visual sync** — drive LEDs or a small OLED display in time with the note changes
