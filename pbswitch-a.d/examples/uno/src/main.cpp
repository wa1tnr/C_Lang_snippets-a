/* main.cpp - main program 9 September 2024 */
#include <Arduino.h>
#include "hoosg.h"
// #include "timeWasters.h"

void setup() {
  initSerial();
  initGPIO();
  blink();
  Serial.println(" blink() already ran.");
}

void newLine() { Serial.write('\n'); }

int counter = -1;

void actuate() {
  counter++;
  newLine();
  Serial.print(counter);
  Serial.print("     TADA");
}

bool readingSwitch() {
  bool held = false;
  held = scanPbSwitch();
  return held;
}

int hbeat = -1;
int iHBeat = -1;

void showHBeat() {
  Serial.write(' ');
  Serial.write('.');
  Serial.write(' ');
}

void iHeartbeat() {
  int hbInterval = (128 - 10); /* 16384 */
  hbeat++;
  if (hbeat > hbInterval) {
    showHBeat();
    hbeat = -1;
  }
}

void heartbeat() {
  int iHbIval = (4096 - 10);
  iHBeat++;
  if (iHBeat > iHbIval) {
    iHeartbeat();
    iHBeat = -1;
  }
}

void loop() {
  bool switchActive = false;
  switchActive = readingSwitch();
  if (switchActive == true) {
    actuate();
    switchActive = false;
  }
  heartbeat();
}

/* reformat ctrl shift i as in india which F1 menu tells you */

/* end */
