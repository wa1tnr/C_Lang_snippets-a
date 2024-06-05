void prime_printing() {
  Serial.write('\n');
  Serial.write('\n');
  Serial.write(' ');
  Serial.write('\n');
  Serial.write(' ');
}

const int8_t b8 = 123;
const int8_t c8 = 119;


void setup() {
  Serial.begin(9600);
  prime_printing();
  int16_t result = b8 * c8;
  Serial.print(" result: ");
  Serial.println(result);
  while(-1) {
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
