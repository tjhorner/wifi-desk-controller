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

  for (int i = 0; i < sizeof(pins_to_test); i++) {
    pinMode(pins_to_test[i], INPUT);
  }

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  delay(100);

  for (int i = 0; i < sizeof(pins_to_test); i++) {
    Serial.print("Waiting for pin ");
    Serial.print(pins_to_test[i] + 1);
    Serial.println();

    while (digitalRead(pins_to_test[i]) == LOW) {
      delay(50);
    }

    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
  }
#else
  Serial.println("Initializing test target...");

  for (int i = 0; i < sizeof(pins_to_test); i++) {
    pinMode(pins_to_test[i], OUTPUT);
    digitalWrite(pins_to_test[i], LOW);
  }
#endif
}

void loop() {
#ifdef TEST_TARGET
  for (int i = 0; i < sizeof(pins_to_test); i++) {
    Serial.print("Pulsing pin ");
    Serial.print(pins_to_test[i] + 1);
    Serial.println();

    digitalWrite(pins_to_test[i], HIGH);
    delay(1000);
    digitalWrite(pins_to_test[i], LOW);
  }
#endif
}