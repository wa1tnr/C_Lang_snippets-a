#include <Arduino.h>


char buffer[64];

void print_me() {
  Serial.println(buffer);
}

#ifdef __cplusplus
extern "C" {
#endif

void do_the_thing() {
    uint8_t test[4] = { 22, -44, -88, 44 };

    snprintf(buffer, sizeof buffer, "%s", "\tuint8_t test[4] = { 22, -44, -88, 44 };\r\n");
    print_me(); // Serial.println(buffer);

    snprintf(buffer, sizeof buffer, "%s", "\ttest[0]: ");
    print_me();

    snprintf(buffer, sizeof buffer, "%B\r\n\r\n", test[0]);
    print_me();

    snprintf(buffer, sizeof buffer, "\t%s", "test[1] holds -44:\r\n");
    print_me();

    snprintf(buffer, sizeof buffer, "%s", "\ttest[1]: ");
    print_me();

    snprintf(buffer, sizeof buffer, "%B\r\n", test[1]);
    print_me();

    int16_t p = (int16_t) test[1];
    int16_t q = 256 - p;
    int8_t  r = 212;
    int8_t  s = (int8_t) 212;
    int16_t t = 212;

    snprintf(buffer, sizeof buffer, "\t      p: %X\r\n", p);
    print_me();

    snprintf(buffer, sizeof buffer, "\t      q: %X\r\n", q);
    print_me();

    snprintf(buffer, sizeof buffer, "\t      r: %X\r\n", r);
    print_me();

    snprintf(buffer, sizeof buffer, "\t      s: %X\r\n", s);
    print_me();

    snprintf(buffer, sizeof buffer, "\t      t: %X\r\n", t);
    print_me();

    snprintf(buffer, sizeof buffer, "%s\n", "");
    print_me();

    for (int i = 0; i < 4; i++) {
        int16_t temp = (test[i] << 8 >> 8);
        snprintf(buffer, sizeof buffer, "%d\n", temp);
        print_me();
    }
}

#ifdef __cplusplus
}
#endif

void setup_serial() {
  Serial.begin(9600);
}

void setup() {
    setup_serial();
    do_the_thing(); // _Gerry_ a gus van san film
}

void loop() { }

// end.
