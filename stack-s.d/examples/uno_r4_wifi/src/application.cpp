/* application.c */
/* Tue  9 Jul 22:32:31 UTC 2024 */

#include <Arduino.h>
#include "stack.h"


int _plus() {
    int a = pop();
    push(a + pop());
}

void printTOS() {
    Serial.print(TOS);
    Serial.write(' ');
}

void job() {
    push(17); printTOS();
    push(23); printTOS();
    _plus();  printTOS();
}

void setup() {
    delay(4100);
    Serial.begin(115200);
    Serial.write('\n');
    job();
}

void loop() {
    delay(50);
}
