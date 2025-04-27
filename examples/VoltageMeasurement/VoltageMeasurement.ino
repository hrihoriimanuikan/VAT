#include <VAT.h>

void setup() {
  Serial.begin(9600);
  setAnalogPins("UNO");
}

void loop() {
  float voltage = voltagemetr(0); // Измерить напряжение на A0
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  delay(1000);
}
