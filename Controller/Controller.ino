#define PIN_VRX  15
#define PIN_VRY  2
#define PIN_POT  4

#define DEAD_ZONE 0.35

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

float normaliseAxis(int raw) {
  float value = (raw / 4095.0) * 2.0 - 1.0;

  if (fabs(value) < DEAD_ZONE) {
    value = 0.0;
  }

  return value;
}

// Returns -1.0 to 1.0
float getX() {
  return normaliseAxis(analogRead(PIN_VRX));
}

// Returns -1.0 to 1.0  (up = positive)
float getY() {
  return normaliseAxis(analogRead(PIN_VRY));
}

// Returns 0.0 to 360.0
float getRot() {
  return ((float)analogRead(PIN_POT) / 4095.0) * 360.0f;
}

void loop() {
  // Example usage — replace with your own logic
  Serial.print(getX());   
  Serial.print(',');
  Serial.print(getY());  
  Serial.print(',');
  Serial.println(getRot());
  delay(16);
}
