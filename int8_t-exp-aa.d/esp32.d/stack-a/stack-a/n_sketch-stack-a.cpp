/* psp.cpp */
// Sat 15 Jun 23:17:53 UTC 2024

#include <Arduino.h>
#define PSTACKSIZE 64 /* 64 cells */ /* forth.h */

char buffer[64];
#define EOL "\r\n"

void print_me() { Serial.print(buffer); }
void print_cr() { Serial.println(""); }

#ifdef __cplusplus
extern "C" {
#endif

unsigned int pstack[PSTACKSIZE];
unsigned int *psp;

void push(int new_tos) {
    int pspInt;
    int old_psp_address = (int)&psp;
    print_cr();


    // says: old_psp_address: 3FFC1BC0

    Serial.println("\tLINE 28: looks like empty stack psp address:");


    Serial.print("\told_psp_address: ");
    Serial.println(old_psp_address, HEX);

    --psp; // make a new space on the stack
    psp[0] = new_tos;
    print_cr();

    pspInt = (int)psp;

    Serial.print("\tpsp: ");
    Serial.println(pspInt, HEX);

    pspInt = (int)*psp;
    Serial.print("\t*psp: ");
    Serial.println(pspInt, HEX);
}

int pop() {
    int p = psp[0];
    // int p = (int) *psp;
    psp++;
    return p;
}

void print_psp_addr_val(uint8_t index) {
    unsigned int *psp_rs = &psp[index];
    int address = ((unsigned int)psp_rs - 4);
    snprintf(buffer, sizeof(buffer), "\trufus_psp[%d]: %12X: ", index, address);
    print_me();

    int pq = psp[index];
    snprintf(buffer, sizeof(buffer), "%8X", pq);
    print_me();
    print_cr();
}

#ifdef __cplusplus
}
#endif

void groovy_fkn_report_a() {
    Serial.println("\thex 3FFC1CBC 3FFC1BC0 - . FC  ok");
    Serial.println("\thex FC decimal . 252  ok");
    Serial.println("\thex FC 4 / . 3F  ok");
    Serial.println("\thex 3F decimal . 63  ok");
}

void test_aa() {
    int a = 5;
    push(a);
    Serial.println("LINE 81: test_aa");
    print_psp_addr_val(0);

    Serial.print(EOL);

    Serial.println("SYNOPSIS:");

    Serial.print("\tpsp: 3FFC1CBC  .. is .. ");

    Serial.println("pstack[63]");

    Serial.print("\t*psp: 5  .. is .. ");
#if 0
LINE 81: test_aa
        rufus_psp[0]:     3FFC1CB8:        5
#endif


    Serial.println("");
    int b = 3;

    groovy_fkn_report_a();

    push(b);
    print_psp_addr_val(0);
    print_cr();
    int c = pop();
    Serial.print("LINE 65: c = ");
    Serial.println(c);
    int d = pop();
    Serial.print("LINE 68: d = ");
    Serial.println(d);
    int e = c * d;
    Serial.print("LINE 72: e = c * d = ");
    Serial.println(e);
}

void tests() { test_aa(); }

void setup_serial() {
    Serial.begin(9600);
    Serial.print("\r\nok\r\n");
}

void setup() {
    setup_serial();

    int pstack_index = PSTACKSIZE - 1;
    psp = &pstack[pstack_index];

    unsigned int *pstack_rs = &pstack[pstack_index];
    int address = ((unsigned int)pstack_rs - 4);

    snprintf(buffer, sizeof(buffer), "\tLINE 109: says 1CBC (highest)%s", EOL);

    print_me();

    snprintf(buffer, sizeof(buffer),
             "\t - rufus_pstack[%d]: %12X: ", pstack_index, address);
    print_me();

    int pstackq = pstack[pstack_index];
    snprintf(buffer, sizeof(buffer), "%8X", pstackq);
    print_me();
    print_cr();

    tests();
}

void loop() {}

// end.
