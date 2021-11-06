const byte DIGITS[] = { A5, A4, A3, A2 };
const byte SEGMENTS[] = { 13, 12, 11, 10, 9, 8, 7, 6 };
const byte numericMaps[10] = { B00111111, B00000110, B01011011, B01001111, B01100110, B01101101, B01111101, B00000111, B01111111, B01100111 };

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }
  delay(5);
  Serial.println("Initialised");
  delay(5);
  
  for (byte i = 0; i < 4; i++) {
    byte pin = DIGITS[i];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  for (byte i = 0; i < 8; i++) {
    byte pin = SEGMENTS[i];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop() { 
  byte characters[4] = { numericMaps[8], numericMaps[9], numericMaps[6], numericMaps[7] };
  writeDisplay(characters);
}

void writeDisplay(byte digets[4]) {
  for (byte i = 0; i < 4; i++) {
    clearDisplay();
    byte digit = digets[i];
    setSegments(digit);
    digitalWrite(DIGITS[i], LOW);
  }
}

void setSegments(byte state) {
  for (byte i = 0; i < 8; i++) {
    bool bit = bitRead(state, i);
    byte pin = SEGMENTS[i];
    digitalWrite(pin, bit);
  }
}

void clearDisplay() {
  for (byte pin : DIGITS) {
    digitalWrite(pin, HIGH);
  }
}