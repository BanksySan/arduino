const byte PIN_COUNT = 14;
const word DELAY = 50;

void setup() {
  for (byte i = 0; i < PIN_COUNT; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (byte i = 0; i < PIN_COUNT; i++) {
    for (byte j = 0; j < PIN_COUNT; j++) {
      digitalWrite(j, i == j);
    }
    delay(DELAY);
  }

  for (byte i = PIN_COUNT - 1; i != 255; i--) {
    for (byte j = 0; j < PIN_COUNT; j++) {
      digitalWrite(j, i == j);
    }
    delay(DELAY);
  }
}
