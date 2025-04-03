#include <Arduino.h>
#define pinLed 2
#define pinBoot 0

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(pinBoot, INPUT_PULLUP);
  Serial.begin(9600);

  for (int i = 0; i <= 10; i++)
  {
    for (int j = 0; j <= 10; j++)
    {
      Serial.printf(" %d x %d = %d \n\r", i, j, i * j);

      //  Serial.print(i);
      //  Serial.print("x");
      //  Serial.print(j);
      //  Serial.print(" = ");
      //  Serial.println(i * j);
    }
    Serial.println("-------------------------------");
  }
}

void loop()
{
}