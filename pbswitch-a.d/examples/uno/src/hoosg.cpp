/* hoosg.cpp library */

#include "timeWasters.h"
#include <Arduino.h>

#define SHOWN_BLINKS 7

const int pinLED = 8;
const int pbSwitch = 9;
const int testBlinkCount = (SHOWN_BLINKS * 2) + 2;

void newLine() {
  Serial.write('\r');
  Serial.write('\n');
}

bool state = true;

void toggleLED() {
  state = !state;
  digitalWrite(pinLED, state);
}

void sendToLEDDirect() { toggleLED(); }

void debouncePbSw() {
  delay(10); // TODO - cheating!
}

bool scanPbSwitch() {
  int pbSwState = digitalRead(pbSwitch);
  return pbSwState;
}

void blink() {
  for (int iterations = testBlinkCount; iterations > 1; iterations--) {
    toggleLED();
    waitSome();
  }
}

void initGPIO() {
  pinMode(pinLED, OUTPUT);
  pinMode(pbSwitch, INPUT);
}

void initSerial() {
  Serial.begin(9600);
  Serial.println("hi");
  Serial.print(__DATE__);
  Serial.write(' ');
  Serial.print(__TIME__);
  Serial.write('z');
  newLine();
}

/* result: LED properly wired */
void testLED() {
  digitalWrite(pinLED, 1);
  while (-1)
    ;
}

/* Mon  9 Sep 23:59:48 UTC 2024 */
/* kuklaFranOllie kanamaris */
/* end */
