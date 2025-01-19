/* stack.cpp - shattuck's stack */
/* Sun 19 Jan 02:54:35 UTC 2025 */

#include <Arduino.h>
#include "macros.h"

/* https://github.com/CharleyShattuck/Feather-M0-interpreter/blob/master/Interpreter.ino#L11-L44
 */

/* This example code is in the public domain */

/* Data stack for parameter passing
   This "stack" is circular,
   like a Green Arrays F18A data stack,
   so overflow and underflow are not possible
   Number of items must be a power of 2 */

const int STKSIZE = 8;
int STKMASK = 7;
int stack[STKSIZE];
int p = 0;

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
