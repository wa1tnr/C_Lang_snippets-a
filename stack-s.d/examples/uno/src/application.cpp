/* application.c */
/* Wed 10 Jul 07:59:06 UTC 2024 */

#include <Arduino.h>

#include "stack.h"

const byte pinMAX = 10;
const byte pinMIN = 1;

void _plus() {
  int a = pop();
  push(a + pop());
}

void printTOS() {
  Serial.print(TOS);
  Serial.write(' ');
}

void stackJob() {
  push(17);
  printTOS();
  push(23);
  printTOS();
  _plus();
  printTOS();
}

void blink() { /* n -- */
  int pin = pop();
  digitalWrite(pin, HIGH);
  delay(400);
  digitalWrite(pin, LOW);
  delay(400);
}

void strobeLeds() {
  for (byte pin = pinMAX; pin > pinMIN; pin--) {
    push(pin);
    blink();
  }
}

void ledsJob() {
  for (;;) {
    strobeLeds();
  }
}

void job() {
  ledsJob();
  stackJob();
}

void setupGPIO() {
  for (byte pin = pinMAX; pin > pinMIN; pin--) {
    pinMode(pin, OUTPUT);
  }
}

void setupSerial() {
  Serial.begin(115200);
  Serial.write('\n');
}

void setup() {
  delay(700);
  setupGPIO();
  setupSerial();
  job();
}

void loop() { delay(50); }

// end.
