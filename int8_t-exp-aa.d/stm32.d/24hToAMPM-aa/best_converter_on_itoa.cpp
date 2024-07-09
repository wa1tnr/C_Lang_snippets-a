// Tue  9 Jul 18:46:40 UTC 2024

/* program */

void report(int prcount, int prp) {
  char buffer[32];
  snprintf(buffer, sizeof buffer, "  %02d %02d  ", prcount, prp);
  Serial.print(buffer);
  delay(800);
}

void timeMaths() {
  int count = -1;
  for (;;) {
    count++;
    int p = count % 12;
    int prp = p + (p == 0) * 12;
    count = (count % 24);
    report(count, prp);
  }
}

void setupSerial() {
  Serial.begin(115200);
  delay(500);
  while (!Serial)
    ;
  Serial.write('\n');
}

void setup() {
  delay(1900);
  setupSerial();
  timeMaths();
}

void loop() { ; }
/* end of program. */
// bye
