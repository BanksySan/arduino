#include "serialComms.h"

const byte xPins[4] = { 4U, 5U, 6U, 7U };
const byte yPins[4] = { 8U, 9U, 10U, 11U };
const byte xSize = 4U;
const byte ySize = 4U;
const word DELAY = 1;
bool xPinStates[xSize] = { LOW, LOW, LOW, LOW };
bool yPinStates[ySize] = { LOW, LOW, LOW, LOW };

void setup() {
  //  setupSerialComms(BAUD_RATE);
  setUpPins();
  setUpTimer();
}

void loop() {
  Serial.println("Click: A");
  xPinStates[0] = LOW;
  xPinStates[1] = HIGH;
  xPinStates[2] = LOW;
  xPinStates[3] = LOW;
  yPinStates[0] = HIGH;
  yPinStates[1] = HIGH;
  yPinStates[2] = HIGH;
  yPinStates[3] = HIGH;
  delay(250);
  Serial.println("Click: B");
  xPinStates[0] = HIGH;
  xPinStates[1] = LOW;
  xPinStates[2] = LOW;
  xPinStates[3] = LOW;
  yPinStates[0] = HIGH;
  yPinStates[1] = HIGH;
  yPinStates[2] = HIGH;
  yPinStates[3] = HIGH;
  delay(250);
}

void setUpPins() {
  for (byte i = 0; i < xSize; i++) {
    pinMode(xPins[i], OUTPUT);
  }

  for (byte i = 0; i < ySize; i++) {
    pinMode(yPins[i], OUTPUT);
  }
}

void setUpTimer() {
  noInterrupts();
  #pragma region  Timer1
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1C = 0;
  TIMSK1 = 0;

  TIMSK1 |= (1 << TOIE1);
  TCCR1B |= (1 << CS10);
  #pragma endregion
  #pragma region Timer2
  TCCR2A = 0;
  TCCR2B = 0;
  TIMSK2 = 0;
  
  TCCR2B |= (1 << CS20);
  TIMSK2 |= (1 << OCIE2A);
  OCR2A = 
  #pragma endregion
  #pragma region Reset all timers
  TCNT0 = 0;
  TCNT1 = 0;
  TCNT2 = 0;
  #pragma endregion
  interrupts();
}

void paint() {
  for (byte i = 0; i < xSize; i++) {
    digitalWrite(xPins[i], xPinStates[i]);
  }
  
  for (byte i = 0; i < ySize; i++) {
    digitalWrite(yPins[i], yPinStates[i]);
  }
}

ISR(TIMER1_OVF_vect) {
  paint();
}