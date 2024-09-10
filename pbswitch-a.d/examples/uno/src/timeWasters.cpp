/* timeWasters.cpp */

// not necessary // #include <Arduino.h>
void nopp() {
  // empty function
}

void waitLess() {
  for (volatile int k = 299; k > 1; k--) {
    nopp();
  }
}

void waitSome() {
  for (volatile int j = 999; j > 1; j--) {
    waitLess();
  }
}

/* end */
