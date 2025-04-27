#include <VAT.h>

void setup() {
  Serial.begin(9600);
  setAnalogPins("UNO");
}

void loop() {
  float current = currentmetr(0, 10.0); // Измерить ток через 10 Ом на A0
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");
  delay(1000);
}
