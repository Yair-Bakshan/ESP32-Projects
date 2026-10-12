# Simon Says

The classic memory game on the ESP32. The board lights up a growing sequence of LEDs with a tone for each one, and you repeat it with the buttons.

## Hardware

| Component | Pins |
|---|---|
| LEDs (3) | GPIO 5, 18, 19 |
| Buttons (3) | GPIO 21, 22, 23 (`INPUT_PULLUP`, other leg to GND) |
| Passive buzzer | GPIO 4 |

Each button controls the LED with the same index: the button on GPIO 21 goes with the LED on GPIO 5, and so on.

| Index | LED | Button | Tone |
|---|---|---|---|
| 0 | GPIO 5 | GPIO 21 | 329 Hz (E4) |
| 1 | GPIO 18 | GPIO 22 | 261 Hz (C4) |
| 2 | GPIO 19 | GPIO 23 | 392 Hz (G4) |

## Wiring

```
GPIO 5  ──── [LED 0] ──── [220 Ω] ──── GND
GPIO 18 ──── [LED 1] ──── [220 Ω] ──── GND
GPIO 19 ──── [LED 2] ──── [220 Ω] ──── GND

GPIO 21 ──── [Button 0] ──── GND
GPIO 22 ──── [Button 1] ──── GND
GPIO 23 ──── [Button 2] ──── GND

GPIO 4  ──── [Buzzer +] ──── GND
```

## How To Play

1. Watch the sequence of lights and tones.
2. Repeat it with the buttons, in the same order.
3. After each correct round, one more step is added and the sequence plays faster.
4. A wrong button, or 7.5 seconds without input, ends the game. All LEDs flash and a new game starts.

## How It Works

The sketch is a state machine with three states.

```
SHOW_SEQUENCE   add one random step, then play the whole sequence
PLAYER_INPUT    wait for button presses
                correct press  -> next step; sequence complete -> SHOW_SEQUENCE
                wrong press or timeout -> GAME_OVER
GAME_OVER       flash all LEDs, reset the sequence and the speed
                then -> SHOW_SEQUENCE
```

- **Difficulty:** the delay between steps starts at 400 ms and drops by 20 ms after each completed round.
- **Debounce:** presses closer than 50 ms apart are ignored.
- **Feedback:** every press lights its LED and plays its tone.

## Usage

1. Wire the LEDs, buttons and buzzer as shown above.
2. Upload `Simon_Says.ino`.
3. Watch the first step and repeat it.

## Ideas

- **Fourth button and LED:** extend the arrays to four elements for the classic four-color game.
- **High score:** keep the longest sequence and show it on an OLED display.
- **Difficulty modes:** choose the starting speed with a potentiometer.
