/* main.cpp - main program 9 September 2024 */
#include "hoosg.h"
#include "pbswitch.h"
#include <Arduino.h>

void setup() {
  initSerial();
  initGPIO();
  blink();
  Serial.println(" blink() already ran.");
}

void loop() { pbSwitchLoop(); }

/* reformat ctrl shift i as in india which F1 menu tells you */

/* end */
