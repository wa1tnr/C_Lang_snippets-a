/* pbswitch.cpp  10 September 2024 */

#include <Arduino.h>
#include "hoosg.h"
#include "consts.h"

int counter = -1;
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

void actuate() {
  counter++;
  newLine();
  Serial.print(counter);
  Serial.print("     TADA");
}

bool scanPbSwitch() {
  bool pbSwState = digitalRead(pbSwitch);
  return pbSwState;
}

bool readingSwitch() {
  bool held = false;
  held = scanPbSwitch();
  return held;
}

void pbSwitchLoop() {
  bool switchActive = false;
  switchActive = readingSwitch();
  if (switchActive == true) {
    actuate();
    switchActive = false;
  }
  heartbeat();
}

/* end */
