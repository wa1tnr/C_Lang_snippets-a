// Tue  9 Jul 19:09:13 UTC 2024
/* program 24 to 12h - 9 July 2024 */

void printCR() { Serial.println(""); }

void vlines() {
  for (int vl = 6; vl > 0; vl--) {
    printCR();
  }
}

void report(int i, int hour24, int hours12) {
  char buffer[32];
  snprintf(buffer, sizeof(buffer), "i = %d, hours12 = %d%d\n", i, hours12 / 10,
           hours12 % 10);
  Serial.println(buffer);
  delay(1200);
}

int hours24g, hours12g, iterg;

void hoursSieve(int fr) {
  hours24g = fr;
  iterg = fr;
  hours12g = -77; // error detection
  if (hours24g == 0) {
    hours12g = 12;
    return;
  }
  if (hours24g <= 12) {
    hours12g = hours24g;
    return;
  }
  hours12g = hours24g - 12;
}

void iterateFactoredMaths() {
  for (int fr = 0; fr <= 23; fr++) {
    hoursSieve(fr);
    report(iterg, hours24g, hours12g);
  }
}

void iterateNonTernaryTimeMaths() {
  for (int i = 0; i <= 23; i++) {
    int hours24 = i;
    int hours12;
    if (hours24 == 0) {
      hours12 = 12;
    } else if (hours24 <= 12) {
      hours12 = hours24;
    } else {
      hours12 = hours24 - 12;
    }
    report(i, hours24, hours12);
  }
}

void iterateTimeMaths() {
  for (int i = 0; i <= 23; i++) {
    int hours24 = i;
    int hours12 = hours24 == 0 ? 12 : hours24 <= 12 ? hours24 : hours24 - 12;
    report(i, hours24, hours12);
  }
}

const int maths = 0; // 0 sieve // 1 nested // 3 ternary

void chosenMaths() {
  if (maths == 3) {
    vlines();
    Serial.println("iterateTimeMaths() ..");
    iterateTimeMaths();
    return;
  }

  if (maths == 0) {
    vlines();
    Serial.println("iterateFactoredMaths() ..");
    iterateFactoredMaths();
    return;
  }
  vlines();
  Serial.println("iterateNonTernaryTimeMaths() ..");
  iterateNonTernaryTimeMaths();
}

void trapped() {
  Serial.print(" TRAPPED ");
  for (;;)
    ;
  Serial.println("");
  Serial.println("NEVER PRINTS");
}

void setupSerial() {
  Serial.begin(115200);
  delay(500);
  while (!Serial)
    ;
  Serial.write('\n');
}

void setup() {
  // put your setup code here, to run once:
  delay(900);
  setupSerial();
  chosenMaths();
  trapped();
}

void loop() {
  // put your main code here, to run repeatedly:
}

/* end */
