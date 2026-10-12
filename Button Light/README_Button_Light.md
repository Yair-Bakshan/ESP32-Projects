# Button Light

Turns an LED on while a button is held. This is the "Hello, World" of hardware.

## Hardware

| Component | Pin | Notes |
|---|---|---|
| Push button | GPIO 4 | `INPUT_PULLUP`, other leg to GND |
| LED | GPIO 5 | In series with a 220 Ω resistor to GND |

Because the sketch uses the internal pull-up resistor, you do not need an external resistor for the button.

## Wiring

```
GPIO 5 ──── [LED] ──── [220 Ω] ──── GND
GPIO 4 ──── [Button] ──── GND
```

## How It Works

The button is active-low. The sketch reads pin 4 and writes the opposite level to pin 5.

| Button | Pin 4 | LED |
|---|---|---|
| Released | HIGH | Off |
| Pressed | LOW | On |

## Usage

1. Wire the LED and the button as shown above.
2. Upload `Button_Light.ino`.
3. Press the button. The LED lights up while you hold it.

## Ideas

- **Toggle mode:** flip the LED on each press instead of following the button.
- **Debounce:** filter bounce with a short delay or the `Bounce2` library.
- **More LEDs:** use several buttons, each with its own LED.
