const byte PIN_V0 = 2;
const byte PIN_RS = 3;
const byte PIN_RW = 4;
const byte PIN_E = 5;
const byte PIN_D0 = 6;
const byte PIN_D1 = 7;
const byte PIN_D2 = 8;
const byte PIN_D3 = 9;
const byte PIN_D4 = 10;
const byte PIN_D5 = 11;
const byte PIN_D6 = 12;
const byte PIN_D7 = 13;

const byte DATA_PINS[] = { PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_D4, PIN_D5, PIN_D6, PIN_D7 };

void setUpPins() {
  pinMode(PIN_RS, OUTPUT);
  pinMode(PIN_RW, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_D0, OUTPUT);
  pinMode(PIN_D1, OUTPUT);
  pinMode(PIN_D2, OUTPUT);
  pinMode(PIN_D3, OUTPUT);
  pinMode(PIN_D4, OUTPUT);
  pinMode(PIN_D5, OUTPUT);
  pinMode(PIN_D6, OUTPUT);
  pinMode(PIN_D7, OUTPUT);
}

const bool REGISTER_DATA = HIGH;
const bool REGISTER_INSTRUCTION = LOW;
const bool RW_READ = HIGH;
const bool RW_WRITE = LOW;
const bool ENABLE = HIGH;  // H, H -> L
const bool DISABLE = LOW;

void setRegister(bool mode) {
  digitalWrite(PIN_RS, mode);
}

void setReadWrite(bool mode) {
  digitalWrite(PIN_RW, mode);
}

void setUpSerial() {
  Serial.begin(9600);
  while (!Serial) { ; }
  Serial.println("Init");
}

void writeData(byte data) {
  Serial.println("Data:  " + String(data, BIN));
  for (byte i = 0; i < sizeof(data); i++) {
    byte b = bitRead(data,i);
    digitalWrite(DATA_PINS[i], b);
  }
}

void clearDisplay() {
  setRegister(REGISTER_INSTRUCTION);
  setReadWrite(RW_WRITE);
  writeData(1);
}

void setup() {
  setUpSerial();
  setUpPins();
}

void loop() {
  ;
}
