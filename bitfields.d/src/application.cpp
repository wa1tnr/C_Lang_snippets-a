/* application.cpp */
/* Sat 18 Jan 16:55:52 UTC 2025 */

#include "stack.h"
#include <Arduino.h>

// /////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////
// ////////////////////  experiment   //////////////////////////

typedef unsigned char Xbytee;

void lclFcnTestBit(Xbytee thatByte, byte bitNumber) {
    Serial.print("  tested:  bit ");
    Serial.print(bitNumber);
    if (bitRead(thatByte, bitNumber) == 1) {
        Serial.println("  is  SET");
        return;
    }
    if (bitRead(thatByte, bitNumber) == 0) {
        Serial.println("  is  RESET");
    }
}

void doTheBit(Xbytee thatByte, byte bitNumber) {
    lclFcnTestBit(thatByte, bitNumber);
}

void initExperiment() {
    Xbytee myByte = 0b00000000;
    for (byte bitNumber = 0; bitNumber < 8; bitNumber++) {
        bool coinFlip = (bool)random(2); // exclusive max as only parm
        if (coinFlip) {
            bitSet(myByte, bitNumber);
        }
        if (!coinFlip) {
            bitClear(myByte, bitNumber);
        }
        doTheBit(myByte, bitNumber);
    }
}

// /////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////

struct Bitfield {
    unsigned int a : 2;
    unsigned int b : 3;
    unsigned int c : 1;
};

void Xmain() {

    Serial.println("inoperative fcn atm\r\n");

    // Bitfield bf = { 2, 5, 1 };

    // std::bitset<8> bits( *(reinterpret_cast<unsigned int*>(&bf)) );

    // std::cout << bits << std::endl;

    // return 0;
}

// /////////////////////////////////////////////////////////////
// /////////////////////////////////////////////////////////////

const byte pinMAX = 10;
const byte pinMIN = 2;

typedef unsigned char bytee;

bytee foo = 3;

// 256       xxx  xxx  xxx  xxx  xxx  xxx  xxx  xxx
//             7    6    5    4    3    2    1    0     add + 1   count
//             place vals
// 256       128   64   32   16    8    4    2    1

struct Date {
    bytee nWeekDay : 3;  // 0..7   (3 bits)
    bytee nMonthDay : 5; // 0..31  (6 bits)
    bytee : 0;           // Force alignment to next boundary.
    bytee nMonth : 4;    // 0..12  (4 bits) (15 not 12 max)
    bytee : 0;           // Force alignment to next boundary.
    bytee nYear : 7;     // 0..100 (7 bits) (127 not 100 max)
};

Date dateHeld;

/* see if 0xFFFFFF is a correct way to mask all bits
   of dateHeld, without over/undershoot */

/* plan of attack failed - tried to cast a struct to a long */

/* want a unified way to grab all bits in one gulp
   in a way at least suggestive of how it is physically
   stored in memory */

void parseDateHeldLShifted() { // ( -- lb )
    /* three bytes uint8_t */
    Date leftByte = dateHeld; // & 0xFF0000;
    // push(leftByte); // year '24' make this '25' later
}

void _assignBitfieldValues() {
    dateHeld.nWeekDay = 4;
    dateHeld.nMonthDay = 23;
    dateHeld.nMonth = 1;
    dateHeld.nYear = 24;
}

void _pushDates() {
    push(dateHeld.nWeekDay);
    push(dateHeld.nMonthDay);
    push(dateHeld.nMonth);
    // push(2000 + dateHeld.nYear);

    parseDateHeldLShifted(); // (  - lb ) holds year
    char something = 1;
    push(something);
}

void _plus() {
    int a = pop();
    push(a + pop());
}

void _drop() {
    pop();
}

void printTOS() {
    Serial.print(TOS);
    Serial.print(' ');
}

void _CRLF() {
    Serial.write('\r');
    Serial.write('\n');
}

void _clrStack() {
    for (bytee element = STKMASK + 1; element > 0; element--) {
        push(0);
    }
}

void _dotS() {
    _CRLF();
    Serial.print(" .s:");
    for (bytee element = STKMASK + 1; element > 0; element--) {
        Serial.write(' ');
        Serial.print(pop());
    }
    _CRLF();
}

void _printSanCheck() {
    Serial.println(" sanity check BB: "); // no hooks eh?
}

void stackJob() {
    _clrStack();
    push(foo);
    _drop();
    push(17);
    printTOS();
    push(23);
    printTOS();
    _plus();
    printTOS();
    _drop();
    _assignBitfieldValues();
    _pushDates();
    _dotS();
    _printSanCheck();
}

void blink() { /* n -- */
    int pin = pop();
    digitalWrite(pin, HIGH);
    delay(400);
    digitalWrite(pin, LOW);
    delay(400);
}

void strobeLeds() {
    for (byte pin = pinMAX; pin > pinMIN; pin--) {
        push(pin);
        blink();
    }
}

void ledsJob() {
    strobeLeds();
}

void switchJob() {
    // Serial.println(" switch job:\n");
    // sw1 sw2 not in use!
    bool sw3 = digitalRead(A0);
    bool sw4 = digitalRead(A1);
    bool sw5 = digitalRead(A2);
    bool sw6 = digitalRead(A3);
    bool sw7 = digitalRead(A4);
    bool sw8 = digitalRead(A5);

    Serial.println();
    Serial.print("0b00");
    Serial.print(sw3);
    Serial.print(sw4);
    Serial.print(' ');
    Serial.print(sw5);
    Serial.print(sw6);
    Serial.print(sw7);
    Serial.println(sw8);
}

void job() {
    ledsJob();
    stackJob();
    switchJob();
    initExperiment();
}

void setupGPIO() {
    for (byte pin = pinMAX; pin > pinMIN; pin--) {
        pinMode(pin, OUTPUT);
    }
}

void printSignonMsgs() {
    Serial.print(" date: ");
    Serial.print(__DATE__);

    Serial.print("   time: ");
    Serial.print(__TIME__);

    Serial.print("z   line: ");
    Serial.println(__LINE__);
}

void setupSerial() {
    Serial.begin(115200);
    Serial.print('\n');
    printSignonMsgs();
}

void setup() {
    delay(700);
    setupGPIO();
    setupSerial();
    Xmain();
    for (;;) {
        job();
    }
}

void loop() {
    delay(50);
}

// end.
