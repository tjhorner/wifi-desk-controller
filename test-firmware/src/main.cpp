#include <Arduino.h>

// These correspond to RJ45 pins 1-6
int pins_to_test[] = {
  D1,
  D2,
  D5,
  D6,
  D7,
  D8
};

void setup() {
  Serial.begin(9600);

#ifdef TEST_HOST
  Serial.println("Initializing test host...");

  for (int &pin : pins_to_test) {
    pinMode(pin, INPUT);
  }

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  delay(100);

  for (int &pin : pins_to_test) {
    Serial.print("Waiting for pin ");
    Serial.print(pin);
    Serial.println();

    while (digitalRead(pin) == LOW) {
      delay(50);
    }

    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
  }
#else
  Serial.println("Initializing test target...");

  for (int &pin : pins_to_test) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
#endif
}

void loop() {
#ifdef TEST_TARGET
  for (int &pin : pins_to_test) {
    Serial.print("Pulsing pin ");
    Serial.print(pin);
    Serial.println();

    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
  }
#endif
}