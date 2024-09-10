/* Tue 10 Sep 20:22:22 UTC 2024 */
/* reverse bits */
/* the real king's life */

#include <Arduino.h>
void newLine() { Serial.println(""); }

void prelude() {
  const int vspaces = 5;
  // wrt discussion about using const in
  // a scoped function,touched on:
  // static makes 'it' stack allocated per zdow

  for (byte iteration = (vspaces + 1); iteration > 1; iteration--) {
    newLine();
  }
}

void sayAnswer(unsigned char q, unsigned char p) {
  newLine();
  Serial.println("  want:  0xBE to 0x7D, reversing the bits:");
  Serial.println("\n TODO:");
  Serial.print(q, HEX);
  Serial.write(' ');
  Serial.print(p, HEX);
  if (q == 0xBE) {
    Serial.println(" yes p is input value.");
  }
  if (p == 0x7D) {
    Serial.println(" yup q is output value expected.");
  }
}

/* gforth */
/* hex 7D binary .  1111101  ok */
/* hex BE binary . 10111110  ok */

/* hex BE binary . 1011 1110  ok */
/* hex 7D binary . 0111 1101  ok */

unsigned char reverse(unsigned char b) {
  unsigned char bb = b; // copy of

  b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
  Serial.print("  b = 0xBE on the input:");
  newLine();

  bb = (bb & 0xF0);
  Serial.print(" bb = (b & 0xF0) eval: 0x");
  Serial.println(bb, HEX);

  bb = (bb >> 4);
  Serial.print(" bb = (bb >> 4)  eval: 0x0");
  Serial.print(bb, HEX);
  Serial.println(" <-- rigged with left pad zero");
  newLine();

  Serial.print(" answer = 0xBE & 0xF0 -- mask bits 7-4");
  newLine();
  Serial.print(" b = (b & 0xF0) >> 4 |");
  Serial.print(" (b & 0x0F) << 4");
  newLine();

  b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
  Serial.print(" b = (b & 0xCC) >> 2 |");
  Serial.print(" (b & 0x33) << 2");
  newLine();
  // parkour
  b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
  Serial.print(" b = (b & 0xAA) >> 1 |");
  Serial.print(" (b & 0x55) << 1");

  newLine();
  return b;
}

/*  1011 1110 to */
/*  0111 1101 */
/*  hex: */

/*  0xBE to /*
  /*  0x7D */

void beginTask() {
  prelude();
  unsigned char q = 0xBE;
  unsigned char p = reverse(q); /* p = 0x7D if mental estimate is right */
  sayAnswer(q, p);
}

void setup() {
  Serial.begin(9600);
  beginTask();
  while (-1)
    ;
}

void loop() {}

/* end */
