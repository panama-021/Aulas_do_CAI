#include <Arduino.h>

#define pinLed 2
#define pinButton 0



void setup() {

  delay(2000);

  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);

  bool buttonState = digitalRead(pinButton);
  

  while (!buttonState)
  {
    digitalWrite(pinLed, HIGH);
    delay(300);
    digitalWrite(pinLed, LOW);
    delay(300);
    buttonState = digitalRead(pinButton);

  }
  

}

void loop() {

}