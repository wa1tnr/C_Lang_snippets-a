/* psp.cpp */
// Sat 15 Jun 23:17:53 UTC 2024

#include <Arduino.h>
#define RSTACKSIZE 64 /* 64 cells */ /* forth.h */

char buffer[64];

void print_me() { Serial.print(buffer); }
void print_cr() { Serial.println(""); }

#ifdef __cplusplus
extern "C" {
#endif

unsigned int pstack[RSTACKSIZE];
unsigned int *psp;

void push(int new_tos) {
    int pspInt;
    --psp; // make a new space on the stack
    psp[0] = new_tos;
    pspInt = (int) psp;
    Serial.print("\tpsp: ");
    Serial.println(pspInt, HEX);
}

int pop() {
    int p = psp[0];
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

void setup_serial() {
    Serial.begin(9600);
    Serial.print("\r\nok\r\n");
    Serial.print("mok\r\n");
    Serial.print("pok\r\n");
}

void setup() {
    setup_serial();
}
void loop() { }

// end.
