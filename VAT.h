#ifndef VAT_H
#define VAT_H

#include "Arduino.h"

// Глобальные переменные
extern float referenceVoltage;
extern float DivisionVoltage;

extern int numAnalogPins; // Теперь переменная изменяемая
extern int virtualAnalogInputs[];
extern int AnalogInputs[];

// Настройки
void setReferenceVoltage(float referenceVoltage);
void setDivisionVoltage(float divisionVoltage);
void setAnalogPins(const String& boardType); // Новая функция выбора платы
void setAnalogPin(int pins);                 // Ручная установка числа пинов

// Ручная подмена значения в виртуальном массиве
void setVirtualAnalogPin(int pinNumber, int value);

// Основные функции измерений
float voltagemetr(int voltagePin);
float currentmetr(int currentPin, float resistance);
float resistance(int resistancePin1, int resistancePin2, float knownResistance);

// Чтение аналоговых входов
void updateVirtualAnalogInputs();

#endif
