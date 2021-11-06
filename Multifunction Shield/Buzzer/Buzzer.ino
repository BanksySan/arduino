#include <I2C.h>
#include <II2C.h>
#include <MPU6050.h>
#include <MultiFuncShield.h>

void setup() {
  MFS.initialize();
  bitWrite(PORTD, 3, 100);
}

void loop() {
}
