/* hoosg.h library or include */

#include <Arduino.h>
#include "timeWasters.h"

const int pinLED = 8;
const int pbSwitch = 9;
#define SHOWN_BLINKS 7
const int testBlinkCount = (SHOWN_BLINKS * 2) + 2;

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
  Serial.print("\n\n");
}

/* result: LED properly wired */
void testLED() {
  digitalWrite(pinLED, 1);
  while (-1)
    ;
}

/* Mon  9 Sep 19:52:08 UTC 2024 */
/* kanamaris */
/* end */
