/* program */

void iterateTimeMaths() {
  char buffer[32];
  for (int i = 0; i <= 23; i++) {
    int hours24 = i;
    int hours12 = hours24 == 0 ? 12 : hours24 <= 12 ? hours24 : hours24 - 12;
    snprintf(buffer, sizeof(buffer), "  i = %d, hours12 = %d%d\n", i,
             hours12 / 10, hours12 % 10);
    Serial.println(buffer);
    delay(1800);
  }
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
  delay(1900);
  setupSerial();
  iterateTimeMaths();
  trapped();
}

void loop() {
  // put your main code here, to run repeatedly:
}
/* end of program. */
