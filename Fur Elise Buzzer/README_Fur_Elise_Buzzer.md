# Für Elise Buzzer

Plays Beethoven's Für Elise on a passive buzzer with the ESP32. The melody and its note durations are stored in two arrays, and the sketch plays them once at startup.

## Hardware

| Component | Pin |
|---|---|
| Passive buzzer (+) | GPIO 5 |
| Passive buzzer (−) | GND |

You need a **passive** buzzer. An active buzzer has a built-in oscillator and can only play one fixed tone.

On some boards GPIO 5 is also the built-in LED, so the LED may blink with the music.

## Wiring

```
GPIO 5 ──── [Buzzer +]
GND    ──── [Buzzer −]
```

A 100 Ω resistor in series is optional but protects the pin.

## How It Works

Each note is played with `tone()` for its duration. The sketch then waits 1.3 times that duration, which leaves a short gap between notes.

```cpp
tone(PIN_5, melody[i], durations[i]);
delay(durations[i] * 1.3);
```

| Property | Value |
|---|---|
| Notes | 2,102 |
| Frequency range | 55 Hz to 2637 Hz |
| Length | About 10 minutes |
| Playback | Once, in `setup()` |

The `loop()` function is empty, so the melody does not repeat. Press the reset button to hear it again.

## Usage

1. Connect the buzzer between GPIO 5 and GND.
2. Upload `Fur_Elise_Buzzer.ino`.
3. The melody starts right after the upload.

## Ideas

- **Repeat:** move the playback loop into `loop()`.
- **Tempo:** multiply `durations[i]` by a global tempo value.
- **Trigger:** wait for a button press before playing.
- **Visuals:** drive LEDs in time with the notes.
