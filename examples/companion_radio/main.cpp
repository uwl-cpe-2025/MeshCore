#include <Arduino.h>

void
setup()
{
  pinMode(LED_BLUE, OUTPUT);
}

void
loop()
{
  digitalWrite(LED_BLUE, HIGH);
  delay(1000);
  digitalWrite(LED_BLUE, LOW);
  delay(1000);
}
