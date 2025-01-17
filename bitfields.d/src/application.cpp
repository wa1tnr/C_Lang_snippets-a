/* application.c */
/* Wed 10 Jul 07:59:06 UTC 2024 */

#include <Arduino.h>

const byte pinMAX = 10;
const byte pinMIN = 1;

typedef unsigned char bytee;

bytee foo = 3;

extern int pop();
extern void push(int n);
extern int stack[];
extern int p;
#define TOSb stack[p]

extern int STKMASK;

void _plus() {
  int a = pop();
  push(a + pop());
}

void printTOS() {
  Serial.print(TOSb);
  Serial.print(' ');
}

void _dotS() {
  push(6);
  push(5);
  push(4);
  push(3);
  push(2);
  push(1);

  push(-99);
  push(-98);
  push(-97);

  Serial.println("\n newlineA:");

  Serial.print(" .s:");
  for (bytee element = STKMASK + 1 ; element > 0; element--)
  {
    Serial.write(' ');
    Serial.write('e');
    Serial.print(pop());
    Serial.write('p');
  }
  Serial.println("\n newlineB:");
  delay(2200);
  push(-55);
  push(-54);

  Serial.print(" .s:");
  for (bytee element = STKMASK + 1 ; element > 0; element--)
  {
    Serial.write(' ');
    Serial.print(pop());
  }
  Serial.println();
}

void stackJob() {
  push(foo);
  push(17);
  printTOS();
  push(23);
  printTOS();
  _plus();
  printTOS();
  Serial.print("\n stack report:   ");
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
  // Serial.print(" aaa "); // one dot all iterations (1:8)
  stackJob();
  switchJob();
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
  // Serial.println(" hello ww ");
  for (;;) {
    job();
  }
}

void loop() { delay(50); }

// end.
