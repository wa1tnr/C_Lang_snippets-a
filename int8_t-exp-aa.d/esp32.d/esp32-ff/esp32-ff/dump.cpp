#include <Arduino.h>

extern unsigned int *psp; /* stack pointer */

#ifdef __cplusplus
extern "C" {
#endif

/* dump 16 bytes of RAM in hex with ascii on the side */

void push(int new_tos) {
    int pspInt = (int)psp;
    Serial.print("\tpsp: ");
    Serial.print(pspInt, HEX);
    Serial.println("\t note: not psp[n] just psp itself.");
    --psp;            // make a new space on the stack
    psp[0] = new_tos; // was psp[1]

    /*
        pspInt = (int) psp;
        Serial.print(" after: psp: ");
        Serial.println(pspInt, HEX);
    */
}

int pop() {
    int p = psp[0];
    psp++;
    return p;
}

void dumpRAM(int iterations) {
    char buffer[16] = "";
    char *ram;
    int p = pop();

    ram = (char *)p;

    snprintf(buffer, sizeof(buffer), "%8X:", p);
    Serial.print(buffer);
    Serial.print(" ");
    for (int i = 0; i < 16; i++) {
        char c = *ram++;
        snprintf(buffer, sizeof(buffer), " %02X", (c & 0xff));
        Serial.print(buffer);
    }
    ram = (char *)p;
    Serial.print(" ");
    for (int i = 0; i < 16; i++) {
        buffer[0] = *ram++;
        if (buffer[0] > 0x7f || buffer[0] < ' ')
            buffer[0] = '.';
        buffer[1] = '\0';
        Serial.print(buffer);
    }
    --psp;
    psp[0] = (p + 16);
}

/* dump 16 bytes of RAM for each iteration */
void rdumps() {
    int iterations = 10; // 16 is nominal here
    for (int i = 0; i < iterations; i++) {
        Serial.println();
        dumpRAM(iterations);
        if (i == 3) {
            Serial.print("\n - - - "); // highlight TOS region
        }
    }
    Serial.println(""); // Serial.println("\nrdumps() has ended.");
}

#ifdef __cplusplus
}
#endif
