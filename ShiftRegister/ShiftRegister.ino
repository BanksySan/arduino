const int PIN_SERIAL_DATA_INPUT = 9;  // Orange
const int PIN_RESET = 13;             // Grey
const int PIN_SHIFT_CLOCK = 12;       // Purple
const int PIN_LATCH_CLOCK = 11;       // Blue (STCP)
const int PIN_OUTPUT_ENABLE = 10;     // Green

const int DELAY_PERIOD = 100;

#pragma region Helpers

void dumpPort(char id, byte port) {
  String bin = String(port, BIN);
  while (bin.length() != 8) {
    bin = "0" + bin;
  }
  String hex = String(port, HEX);
  while (hex.length() != 2) {
    hex = 0 + hex;
  }

  Serial.println(String(id) + ":  " + bin + ", 0x" + hex);
}

#pragma endregion

void setPinModes() {
  pinMode(PIN_SERIAL_DATA_INPUT, OUTPUT);
  pinMode(PIN_RESET, OUTPUT);
  pinMode(PIN_SHIFT_CLOCK, OUTPUT);
  pinMode(PIN_LATCH_CLOCK, OUTPUT);
  pinMode(PIN_OUTPUT_ENABLE, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void setup() {
  Serial.begin(9600);
  setPinModes();

  digitalWrite(PIN_RESET, LOW);
  digitalWrite(PIN_SHIFT_CLOCK, LOW);
  digitalWrite(PIN_LATCH_CLOCK, LOW);
  digitalWrite(PIN_OUTPUT_ENABLE, LOW);
  digitalWrite(PIN_RESET, HIGH);

  while (!Serial) { ; }
}

void loop() {
  digitalWrite(PIN_SHIFT_CLOCK, LOW);
  digitalWrite(PIN_LATCH_CLOCK, LOW);
  delay(1);
  digitalWrite(PIN_SERIAL_DATA_INPUT, HIGH);
  delay(1);
  digitalWrite(PIN_SHIFT_CLOCK, HIGH);
  delay(1);
  digitalWrite(PIN_SHIFT_CLOCK, LOW);
  delay(1);
  digitalWrite(PIN_LATCH_CLOCK, HIGH);
  delay(1000);
}
