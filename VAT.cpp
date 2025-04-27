#include "VAT.h"

float referenceVoltage = 5.0;
float DivisionVoltage = 1.0;

// Максимальное количество аналоговых пинов (максимум для MEGA)
const int maxAnalogPins = 8;

int virtualAnalogInputs[maxAnalogPins];
int AnalogInputs[maxAnalogPins];
int numAnalogPins = 0;  // Будет устанавливаться функцией setAnalogPins

// Макрос отладочной ошибки (можно заменить на вывод в отладочный порт)
#define DEBUG_ERROR(msg) /* ничего не делаем, можно заменить на вывод в отладку */

// Установка пользовательской платы
void setAnalogPins(const String& boardType) {
  if (boardType == "UNO") {
    numAnalogPins = 6;
    for (int i = 0; i < numAnalogPins; ++i) AnalogInputs[i] = i;  // A0-A5 — это 0-5
  } else if (boardType == "ESP32") {
    numAnalogPins = 12;
    int esp32Pins[] = {34, 35, 36, 39, 32, 33, 25, 26, 27, 14, 12, 13};
    for (int i = 0; i < numAnalogPins; ++i) AnalogInputs[i] = esp32Pins[i];
  } else if (boardType == "MEGA") {
    numAnalogPins = 16;
    for (int i = 0; i < numAnalogPins; ++i) AnalogInputs[i] = i;  // A0-A15 — это 0-15
  } else {
    DEBUG_ERROR("Unknown board type");
    numAnalogPins = 0;
  }
}

void setReferenceVoltage(float newReferenceVoltage) {
  referenceVoltage = newReferenceVoltage;
}

void setDivisionVoltage(float newDivisionVoltage) {
  DivisionVoltage = newDivisionVoltage;
}

void setVirtualAnalogPin(int pinNumber, int value) {
  if (pinNumber >= 0 && pinNumber < numAnalogPins) {
    virtualAnalogInputs[pinNumber] = value;
  }
}

// Установка пользовательских номеров пинов вручную (если не через boardType)
void setAnalogPin(int pins) {
  for (int i = 0; i < pins && i < maxAnalogPins; ++i) {
    AnalogInputs[i] = i;
  }
  numAnalogPins = pins;
}

float voltagemetr(int voltagePin) {
  updateVirtualAnalogInputs();
  return referenceVoltage / 1023.0 * virtualAnalogInputs[voltagePin] * DivisionVoltage;
}

float currentmetr(int currentPin, float resistanceValue) {
  updateVirtualAnalogInputs();
  float voltage = referenceVoltage / 1023.0 * virtualAnalogInputs[currentPin] * DivisionVoltage;
  return voltage / resistanceValue;
}

float resistance(int resistancePin1, int resistancePin2, float knownResistance) {
  updateVirtualAnalogInputs();
  float voltage1 = referenceVoltage / 1023.0 * virtualAnalogInputs[resistancePin1] * DivisionVoltage;
  float voltage2 = referenceVoltage / 1023.0 * virtualAnalogInputs[resistancePin2] * DivisionVoltage;
  float amper = voltage1 / knownResistance;
  return amper != 0 ? voltage2 / amper : 0.0;
}

void updateVirtualAnalogInputs() {
  for (int i = 0; i < numAnalogPins; ++i) {
    virtualAnalogInputs[i] = analogRead(AnalogInputs[i]);
  }
}
