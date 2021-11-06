#include <MultiFuncShield.h>

void setup()
{
  MFS.initialize();
}

void loop()
{
  char time[5]; 
  String(millis(), HEX).toCharArray(time, 5);
  MFS.write(time);
}
