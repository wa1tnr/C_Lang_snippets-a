/* stack.h - shattuck's stack */
/* Fri 17 Jan 19:55:26 UTC 2025 */

/*
  https://github.com/CharleyShattuck/Feather-M0-interpreter/blob/master/Interpreter.ino#L11-L44

*/

/* This example code is in the public domain */

/* not all will need an extern prototype */
extern int pop();
extern void push(int n);
extern int stack[];
extern int p;
#define TOS stack[p]
extern int STKMASK;

/* end. */
