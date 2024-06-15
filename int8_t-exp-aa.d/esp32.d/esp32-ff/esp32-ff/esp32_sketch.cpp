#include "cpp_macros.h"
#include <Arduino.h>

char buffer[64];

// clang-format off
void print_me() {
    Serial.print(buffer);
}
// clang-format on

#define EOL "\r\n"

// clang-format off
void print_cr() {
    Serial.println("");
}
// clang-format on

#ifdef __cplusplus
extern "C" {
#endif

#define PSTACKSIZE 64 /* 64 cells */ /* forth.h */

unsigned int pstack[PSTACKSIZE];

unsigned int *psp;

extern void push(int new_tos);

extern int pop();
extern void rdumps();

// clang-format off
#define POFFSET 64 - 0
    // changing 0 to -4
    // will give zero-ref line numbers in hex
// clang-format on

/*
 *
 *   TODO:  find RAM address for 'the thing' you wanted to inspect.
 *
 *          uint8_t or uint16_t ints for example.  Originally wanted
 *          a binary dump of that RAM but hex'll probably work too.
 *
 *          psp[0] = new_tos;
 */

void nopp() {}

void do_the_thing() {
    uint8_t test[4] = {22, (uint8_t)-44, (uint8_t)-88, 44};

    char *buf_ptr;
    buf_ptr = (char *)&buffer;
    int buf_ptr_cint = (int)buf_ptr;

    // int pram = psp[2]; // two under TOS

    char *ram;
    push(0xA5);
    push(0xA5);
    push(0xA5);
    int pq = psp[2];
    ram = (char *)pq;
    snprintf(buffer, sizeof(buffer), "tos[2]: %8X", pq);
    print_me();

    // char c = *ram++;

    char c = *ram;

    snprintf(buffer, sizeof(buffer), " %02X", (c & 0xff));
    print_me();

    int pushed, tossed, saved_push;

    push(0xA5);
    push(0xA5);
    push(0xA5);
    push(0xA5);
    push(0xA5);

    // snprintf(buffer, sizeof buffer, "\t   moy bueno      pspi: $%12X%s",
    // &ram, EOL); print_me();
    int toss = pop();
    if (toss == -17742) {
    }
    snprintf(buffer, sizeof buffer, "\t   trapped in while loop:%s", EOL);
    print_me();
    while (-1)
        ;

#if 0

3FFC1CB4:  00 00 00 00 00 00 00 00 B4 1C FC 3F 00 00 00 00 ...........?....
            4  5  6  7  8  9  A  B  C  D  E  F C0
#endif

    snprintf(buffer, sizeof buffer, "\t      buf_ptr: $%12X%s", buf_ptr_cint,
             EOL);
    print_faked_cr();

    snprintf(buffer, sizeof buffer, "%s%s%s", EOL,
             "\tuint8_t test[4] = { 22, -44, -88, 44 };", EOL);
    print_me(); // Serial.println(buffer);

    buf_ptr = (char *)&buffer;
    pushed = (int)buf_ptr;
    push(pushed - POFFSET); // push address of buffer
    saved_push = pop();
    push(saved_push);

    snprintf(buffer, sizeof buffer, "%s",
             "\tdo_the_thing() saved_push after push(): ");
    print_me();

    snprintf(buffer, sizeof buffer, "gaw \t$%12X", saved_push);
    print_me();

    rdumps();       // dump data stored at or near buf_ptr
    tossed = pop(); // dumpRAM always pushes on the stack as it exits
    if (tossed == -713)
        Serial.println("NEVER WANT TO SEE THIS");

    snprintf(buffer, sizeof buffer, "%s", "\ttest[0]: ");
    print_me();

    snprintf(buffer, sizeof buffer, "$%12X%s%s", test[0], EOL, EOL);
    print_faked();

    print_me();
    print_cr(); // print just a carriage return

    snprintf(buffer, sizeof buffer, "\ttest[1]  holds -44:%s", EOL);
    snprintf(buffer, sizeof buffer, "%s", "\ttest[1]: ");
    print_me();

    snprintf(buffer, sizeof buffer, "$%12X%s", test[1], EOL);
    print_me();
    print_cr();

    snprintf(buffer, sizeof buffer, "\t\t\t%s",
             "gforth: decimal 256 44 - hex . D4  ok");
    print_me();
    print_cr();

    int16_t p = (int16_t)test[1];
    int16_t q = 256 - p;
    int8_t r = 212;
    int8_t s = (int8_t)212;
    int16_t t = 212;

    snprintf(buffer, sizeof buffer, "\t      p: %X%s", p, EOL);
    print_faked();

    snprintf(buffer, sizeof buffer, "\t      q: %X%s", q, EOL);
    print_me();
    print_cr();

    snprintf(buffer, sizeof buffer, "\t\t\t%s",
             "gforth: decimal 256 hex D4 - . 2C  ok\n\t\tREPEAT:\n\n");
    print_me();
    print_cr();

    snprintf(buffer, sizeof buffer, "\t      q: %X%s", q, EOL);
    print_faked_cr();

    snprintf(buffer, sizeof buffer, "\t      r: %X%s", r, EOL);
    print_faked();

    snprintf(buffer, sizeof buffer, "\t      s: %X%s", s, EOL);
    print_faked();

    snprintf(buffer, sizeof buffer, "\t      t: %X%s", t, EOL);
    print_faked();

    snprintf(buffer, sizeof buffer, "%s", EOL);
    print_faked();

    for (int i = 0; i < 4; i++) {
        int16_t temp = (test[i] << 8 >> 8);
        snprintf(buffer, sizeof buffer, "\t\t%d%s", temp, EOL);
        print_faked();
    }
}

#ifdef __cplusplus
}
#endif

void signoff_msg() {
    snprintf(buffer, sizeof buffer, "%s%s", EOL,
             "\tProgram execution trapped in a while loop. ");
    print_me();
}

void setup_serial() {
    Serial.begin(9600);
    Serial.println("testing seventeen abc");
    delay(5555);
}

void setup() {
    setup_serial();
    psp = &pstack[PSTACKSIZE - 1];
    do_the_thing(); // _Gerry_ a gus van san film
    signoff_msg();
    while (-1)
        ;
    Serial.println("program ESCAPED while loop trap.  shred: -77");
}

void loop() {
    Serial.println("THIS MESSAGE NEVER PRINTS.");
    delay(4000);
}

// end.
