/* stack.h - shattuck's stack */
/* Wed 10 Jul 05:03:10 UTC 2024 */

/*
  https://github.com/CharleyShattuck/Feather-M0-interpreter/blob/master/Interpreter.ino#L11-L44

*/

/* This example code is in the public domain */

/* not all will need an extern prototype */
// extern const int STKSIZE;
// extern const int STKMASK;
// extern int stack[];
// extern int p;
// #define TOS stack[p]
// extern void push(int n);
// void push(int n);

// extern int pop();
// int pop();

/* end. */

extern int pop();
extern void push(int n);
extern int stack[];
extern int p;
#define TOSb stack[p]

extern int STKMASK;
