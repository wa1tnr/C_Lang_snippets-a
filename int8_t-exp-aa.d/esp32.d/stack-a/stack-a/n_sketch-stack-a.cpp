/* psp.cpp */
// Sat 15 Jun 23:17:53 UTC 2024

#include <Arduino.h>
#define PSTACKSIZE 64 /* 64 cells */ /* forth.h */

char buffer[64];

void print_me() { Serial.print(buffer); }
void print_cr() { Serial.println(""); }

#ifdef __cplusplus
extern "C" {
#endif

unsigned int pstack[PSTACKSIZE];
unsigned int *psp;

void push(int new_tos) {
    int pspInt;
    --psp; // make a new space on the stack
    psp[0] = new_tos;

    pspInt = (int) &*psp;
    Serial.print("\t&*psp: ");
    Serial.println(pspInt, HEX);

    pspInt = (int) *psp;
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
    int address = (unsigned int)psp_rs;
    snprintf(buffer, sizeof(buffer), "\trufus_psp[%d]: %12X: ", index,
             address);
    print_me();

    int pq = psp[index];
    snprintf(buffer, sizeof(buffer), "%8X", pq);
    print_me();
    print_cr();
}
#ifdef __cplusplus
}
#endif

void test_aa() {
    int a = 5; push(a);
    int b = 3; push(b);
    int c = pop();
    Serial.print("LINE 55: c = ");
    Serial.println(c);
    int d = pop();
    Serial.print("LINE 58: d = ");
    Serial.println(d);
    int e = c * d;
    Serial.print("LINE 62: e = c * d = ");
    Serial.println(e);
}

void tests() {
    test_aa();
}

void setup_serial() {
    Serial.begin(9600);
    Serial.print("\r\nok\r\n");
    Serial.print("mok\r\n");
    Serial.print("pok\r\n");
}

void setup() {
    setup_serial();
    psp = &pstack[PSTACKSIZE-1];
    tests();
}

void loop() { }

// end.
