#include <Arduino.h>

void setup_serial() {
  Serial.begin(9600);
}

char buffer[64];

void print_me() {
  Serial.println(buffer);
}

void setup() {
    setup_serial();
    uint8_t test[4] = { 22, -44, -88, 44 };

    /* now a global: char buffer[64]; */

    snprintf(buffer, sizeof buffer, "%s", "\tuint8_t test[4] = { 22, -44, -88, 44 };\r\n");
    Serial.println(buffer);

    snprintf(buffer, sizeof buffer, "%s", "\ttest[0]: ");
    print_me();

    snprintf(buffer, sizeof buffer, "%b\r\n\r\n", test[0]);
    print_me();
    snprintf(buffer, sizeof buffer, "\t%s", "test[1] holds -44:\r\n");
    print_me();
    snprintf(buffer, sizeof buffer, "%s", "\ttest[1]: ");
    print_me();
    snprintf(buffer, sizeof buffer, "%b\r\n", test[1]);
    print_me();
    int16_t p = (int16_t) test[1];
    int16_t q = 256 - p;
    int8_t  r = 212;
    int8_t  s = (int8_t) 212;
    int16_t t = 212;

    snprintf(buffer, sizeof buffer, "\t      p: %b\r\n", p);
    print_me();
    snprintf(buffer, sizeof buffer, "\t      q: %b\r\n", q);
    print_me();
    snprintf(buffer, sizeof buffer, "\t      r: %b\r\n", r);
    print_me();
    snprintf(buffer, sizeof buffer, "\t      s: %b\r\n", s);
    print_me();
    snprintf(buffer, sizeof buffer, "\t      t: %b\r\n", t);
    print_me();
    snprintf(buffer, sizeof buffer, "%s\n", "");
    print_me();
    for (int i = 0; i < 4; i++) {
        int16_t temp = (test[i] << 8 >> 8);
        snprintf(buffer, sizeof buffer, "%d\n", temp);
        print_me();
    }
}

void loop() { }

// end.
