#include <Arduino.h>

char buffer[64];

void print_me() {
  Serial.print(buffer);
}

#define EOL "\r\n"

#ifdef __cplusplus
extern "C" {
#endif


void do_the_thing() {
    uint8_t test[4] = { 22, (uint8_t) -44, (uint8_t) -88, 44 }; // bs bs and compiler will not have it -Wnarrowing

    snprintf(buffer, sizeof buffer, "%s%s%s", EOL, "\tuint8_t test[4] = { 22, -44, -88, 44 };", EOL);
    print_me(); // Serial.println(buffer);

    snprintf(buffer, sizeof buffer, "%s", "\ttest[0]: ");
    print_me();

    snprintf(buffer, sizeof buffer, "$%12X%s%s", test[0], EOL, EOL);
    print_me();

    snprintf(buffer, sizeof buffer, "\ttest[1]  holds -44:%s", EOL);
    print_me();

    snprintf(buffer, sizeof buffer, "\ttest[1]: " );
    print_me();

    snprintf(buffer, sizeof buffer, "$%12X%s", test[1], EOL);
    print_me();

    int16_t p = (int16_t) test[1];
    int16_t q = 256 - p;
    int8_t  r = 212;
    int8_t  s = (int8_t) 212;
    int16_t t = 212;

    snprintf(buffer, sizeof buffer, "\t      p: %X%s", p, EOL);
    print_me();

    snprintf(buffer, sizeof buffer, "\t      q: %X%s", q, EOL);
    print_me();

    snprintf(buffer, sizeof buffer, "\t      r: %X%s", r, EOL);
    print_me();

    snprintf(buffer, sizeof buffer, "\t      s: %X%s", s, EOL);
    print_me();

    snprintf(buffer, sizeof buffer, "\t      t: %X%s", t, EOL);
    print_me();

    snprintf(buffer, sizeof buffer, "%s", EOL);
    print_me();

    for (int i = 0; i < 4; i++) {
        int16_t temp = (test[i] << 8 >> 8);
        snprintf(buffer, sizeof buffer, "\t\t%d%s", temp, EOL);
        print_me();
    }
}

#ifdef __cplusplus
}
#endif

void signoff_msg() {
    snprintf(buffer, sizeof buffer, "%s%s", EOL, "\tProgram execution trapped in a while loop. ");
        print_me();
}

void setup_serial() {
  Serial.begin(9600);
}

void setup() {
    setup_serial();
    do_the_thing(); // _Gerry_ a gus van san film
    signoff_msg();
    while(-1);
    Serial.println("program ESCAPED while loop trap.  shred: -77");
}

void loop() {
    Serial.println("THIS MESSAGE NEVER PRINTS.");
    delay(4000);
}
 
// end.
