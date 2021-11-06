const byte LATCH_PIN = 4;
const byte SHIFT_PIN = 7;
const byte DATA_PIN = 8;
const byte CONTROL_PINS[] = { LATCH_PIN,
                              SHIFT_PIN,
                              DATA_PIN };
#pragma region LED Control 
const byte LEDS[] = { 13, 12, 11, 10 };

void setLeds(byte state) {  
  for (byte i = 0; i < 4; i++) {
    digitalWrite(LEDS[i], bitRead(state, i));
  }
}
#pragma endregion

void setup() {
  Serial.begin(9600);
  for (byte i = 0; i < 4; i++) {
    pinMode(LEDS[i], OUTPUT);
  }

  for (byte i = 0; i < 3; i++) {
    const byte pin = CONTROL_PINS[i];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  
  while (!Serial) { ; }
  delay(10);
  Serial.println("Initialised");
  delay(10);
  setState(B11111111);
}


void loop() { 
  static byte counter = 0;
  setLeds(counter++);
  delay(1000); 
}

void doShift(bool bit) {
  digitalWrite(SHIFT_PIN, LOW);
  digitalWrite(DATA_PIN, bit);
  digitalWrite(SHIFT_PIN, HIGH);
}

void setState(byte state) {
  digitalWrite(LATCH_PIN, LOW);
  
  // Set all digits high 
  for (byte i = 0; i < 8; i++) {
    doShift(HIGH);
  }

  for (byte i = 0; i < 8; i++) {
    const bool bitState = bitRead(state, i) == 0 ? LOW : HIGH;
    doShift(bitState);
  }

  digitalWrite(LATCH_PIN, HIGH);
}