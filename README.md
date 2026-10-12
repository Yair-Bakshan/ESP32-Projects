# ESP32 Projects

Small hardware projects for the ESP32, written with the Arduino framework. They cover digital input and output, analog input, sound and a complete game.

## Projects

| Project | Description | Hardware |
|---|---|---|
| [Button Light](Button%20Light) | Turns an LED on while a button is held | Button, LED |
| [Controller](Controller) | Reads a joystick and a potentiometer and streams normalized values over Serial | Joystick, potentiometer |
| [Fur Elise Buzzer](Fur%20Elise%20Buzzer) | Plays Für Elise on a passive buzzer | Passive buzzer |
| [Simon Says](Simon%20Says) | Memory game with LEDs, buttons and a buzzer | 3 LEDs, 3 buttons, buzzer |

Each folder has its own README with the pin table, a wiring diagram and usage steps.

## Hardware

- ESP32 development board (for example, a WROOM-32 board)
- LEDs and 220 Ω resistors
- Push buttons
- Passive buzzer
- Joystick module and potentiometer
- Breadboard and jumper wires

## Getting Started

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Add ESP32 support: open **Boards Manager**, search for `esp32` and install the package by Espressif Systems.
3. Clone the repository:

   ```bash
   git clone https://github.com/Yair-Bakshan/ESP32-Projects.git
   ```

4. Open a sketch (`.ino` file). If the IDE asks to move it into a folder with the same name, click **OK**.
5. Select your board (for example, **ESP32 Dev Module**) and the serial port.
6. Click **Upload**.

## License

Released under the [MIT License](LICENSE).
