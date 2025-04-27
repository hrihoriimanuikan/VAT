#include <VAT.h>

void setup() {
  Serial.begin(9600);
  setAnalogPins("UNO");
}

void loop() {
  float current = currentmetr(0, 10.0); // Resistance = 10 Ohm
  Serial.println(current);
}
