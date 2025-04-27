# VAT - Voltage and Current Measurement Library

**VAT** (Voltage and Current Measurement Library) allows you to easily measure voltage, current, and resistance with Arduino boards such as UNO, MEGA, and ESP32.

---

## Features

- Measure voltage with `voltagemetr()`
- Measure current with `currentmetr()`
- Measure resistance with `resistance()`
- Support for UNO, MEGA, and ESP32 boards
- Adjustable reference voltage and voltage divider

---

## Installation

1. Download this repository as ZIP or use GitHub Codespace.
2. Install the library into Arduino IDE via **Sketch → Include Library → Add .ZIP Library...**

---

## Usage

### 1. Voltage Measurement

```cpp
#include <VAT.h>

void setup() {
  Serial.begin(9600);
  setAnalogPins("UNO");
}

void loop() {
  float voltage = voltagemetr(0);
  Serial.println(voltage);
}
