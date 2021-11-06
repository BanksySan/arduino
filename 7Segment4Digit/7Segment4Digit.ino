#define A_SEGMENT 13
#define B_SEGMENT 12
#define C_SEGMENT 11
#define D_SEGMENT 10
#define E_SEGMENT 9
#define F_SEGMENT 8
#define G_SEGMENT 7
#define DP_SEGMENT 6

const byte DIGIT_PINS[] = { A5, A4, A3, A2 };
const byte SEGMENT_PINS[] = { A_SEGMENT,
                              B_SEGMENT,
                              C_SEGMENT,
                              D_SEGMENT,
                              E_SEGMENT,
                              F_SEGMENT,
                              G_SEGMENT,
                              DP_SEGMENT };

void setup() {
  Serial.begin(9600);
  do {
    delay(5);
  } while (!Serial);

  Serial.println("Initialised");
  for (byte pin: DIGIT_PINS) {
    Serial.println("  Digit pin:  " + String(pin));
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  for (byte pin: SEGMENT_PINS) {
    Serial.println("Segment pin:  " + String(pin));
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(500);
  }
}

void loop() { 
  for (byte pin: SEGMENT_PINS) {
    digitalWrite(pin, LOW);
  }

  for (byte pin: SEGMENT_PINS) {
    Serial.println("Segment pin:  " + String(pin));
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(500);
  }
}



// void serialEvent() {
//   String incoming = Serial.readString();
//   for (byte i = 0; i < 4; i++) {
//     bool state = (char) incoming[i] == '*';
  
//     digitalWrite(DIGIT_PINS[i], state);
//     Serial.print(String(i) + ":" + String(state) + "\n");
//   }
// }