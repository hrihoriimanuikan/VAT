#include <VAT.h>

void setup() {
  Serial.begin(9600);
  setAnalogPins("UNO");
}

void loop() {
  float resistanceValue = resistance(0, 1, 1000.0); // Known resistance = 1k Ohm
  Serial.println(resistanceValue);
}
