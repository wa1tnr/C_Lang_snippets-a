/* stack.cpp - shattuck's stack */
/* Mon 20 Jan 21:35:14 UTC 2025 */

#include "macros.h"
#include <Arduino.h>
#include <stdint.h>

/* https://github.com/CharleyShattuck/Feather-M0-interpreter/blob/master/Interpreter.ino#L11-L44
 */

/* This example code is in the public domain */

/* Data stack for parameter passing
   This "stack" is circular,
   like a Green Arrays F18A data stack,
   so overflow and underflow are not possible
   Number of items must be a power of 2 */

const uint8_t STKSIZE = 8;
uint8_t STKMASK = 7;

int stack[STKSIZE];
uint8_t p = 0;

// RAM:   [==        ]  16.0% (used 328 bytes from 2048 bytes)
// Flash: [=         ]  11.7% (used 3788 bytes from 32256 bytes)

/* push n to top of data stack */
void push(int n) {
    p = (p + 1) & STKMASK;
    TOS = n;
}

/* return top of stack */
int pop() {
    int n = TOS;
    p = (p - 1) & STKMASK;
    return n;
}

/* end. */
