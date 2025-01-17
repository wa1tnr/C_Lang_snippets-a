/* application.c */
/* Wed 10 Jul 07:59:06 UTC 2024 */

#include <Arduino.h>
#include "stack.h"

const byte pinMAX = 10;
const byte pinMIN = 1;

typedef unsigned char bytee;

bytee foo = 3;

struct Date {
   unsigned nWeekDay  : 3;    // 0..7   (3 bits)
   unsigned nMonthDay : 6;    // 0..31  (6 bits)
   unsigned           : 0;    // Force alignment to next boundary.
   unsigned nMonth    : 4;    // 0..12  (4 bits)
   unsigned nYear     : 8;    // 0..100 (7 bits)
};

Date dateHeld;

void _pushDates() {
  dateHeld.nWeekDay = 4;
  dateHeld.nMonthDay = 23;
  dateHeld.nMonth = 1;
  dateHeld.nYear = 24;
  push(dateHeld.nWeekDay);
  push(dateHeld.nMonthDay);
  push(dateHeld.nMonth);
  push(2000 + dateHeld.nYear);
}

void _plus() {
  int a = pop();
  push(a + pop());
}

void _drop() {
  pop();
}

void printTOS() {
  Serial.print(TOSb);
  Serial.print(' ');
}

void _CRLF() {
  Serial.write('\r');
  Serial.write('\n');
}

void _clrStack() {
  for (bytee element = STKMASK + 1 ; element > 0; element--) {
    push(0);
  }
}

void _dotS() {
  _CRLF();
  Serial.print(" .s:");
  for (bytee element = STKMASK + 1 ; element > 0; element--)
  {
    Serial.write(' ');
    Serial.print(pop());
  }
  _CRLF();
  //  Serial.write(' ');
}

void stackJob() {
  _clrStack();
  push(foo);
  _drop();
  push(17);
  printTOS();
  push(23);
  printTOS();
  _plus();
  printTOS();
  _drop();
  _pushDates();
  _dotS();
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
    strobeLeds();
}

void switchJob() {
  // Serial.println(" switch job:\n");
  // sw1 sw2 not in use!
  bool sw3 = digitalRead(A0);
  bool sw4 = digitalRead(A1);
  bool sw5 = digitalRead(A2);
  bool sw6 = digitalRead(A3);
  bool sw7 = digitalRead(A4);
  bool sw8 = digitalRead(A5);

  Serial.println();
  Serial.print("0b00");
  Serial.print(sw3);
  Serial.print(sw4);
  Serial.print(' ');
  Serial.print(sw5);
  Serial.print(sw6);
  Serial.print(sw7);
  Serial.println(sw8);
}

void job() {
  ledsJob();
  stackJob();
  // switchJob();
}

void setupGPIO() {
  for (byte pin = pinMAX; pin > pinMIN; pin--) {
    pinMode(pin, OUTPUT);
  }
}

void setupSerial() {
  Serial.begin(115200);
  Serial.print('\n');
  Serial.println(" sample of serial printing");
}

void setup() {
  delay(700);
  setupGPIO();
  setupSerial();
  for (;;) {
    job();
  }
}

void loop() { delay(50); }

// end.
