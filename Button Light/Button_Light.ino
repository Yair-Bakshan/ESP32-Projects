const int buttonPin = 4;
const int ledPin = 5;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int useCase = buttonState == LOW ? HIGH : LOW;
  digitalWrite(ledPin, useCase);
}