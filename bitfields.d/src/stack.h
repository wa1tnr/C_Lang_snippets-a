/* stack.h - shattuck's stack */
/* Mon 20 Jan 21:35:14 UTC 2025 */
#include <stdint.h>

/*
  https://github.com/CharleyShattuck/Feather-M0-interpreter/blob/master/Interpreter.ino#L11-L44

*/

/* This example code is in the public domain */

/* not all will need an extern prototype */

extern const uint8_t STKMASK ; // why here tho

extern int stack[];
extern uint8_t p;

extern void push(int n);
extern int pop();

/* end. */
