/* application.cpp */
/* Fri 24 Jan 17:57:15 UTC 2025 */

#include "macros.h"
#include "stack.h"
#include "time_stamp.h"
#include <Arduino.h>

// /////////////////////////////////////////////////////////////
// ////////////////////  experiment   //////////////////////////
// /////////////////////////////////////////////////////////////

const uint8_t pinMAX = '\011'; // for D9
const uint8_t pinMIN = '\002'; // for D2

const uint8_t inPinMAX = 19; // D19 aka A5
const uint8_t inPinMIN = 14; // D14 aka D0

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
        bool coinFlip = (bool)random(2); // exclusive max
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

struct Bitfield {
    unsigned int a : 2;
    unsigned int b : 3;
    unsigned int c : 1;
};

struct dipSwitch {
    uint8_t sw1 : 1;
    uint8_t sw2 : 1;
    uint8_t sw3 : 1;
    uint8_t sw4 : 1;
    uint8_t sw5 : 1;
    uint8_t sw6 : 1;
    uint8_t sw7 : 1;
    uint8_t sw8 : 1;
};

void Xmain() {

    Serial.println(" inoperative fcn atm");

#if 0
    Bitfield bf = { 2, 5, 1 };
    std::bitset<8> bits( *(reinterpret_cast<unsigned int*>(&bf)) );
    std::cout << bits << std::endl;
    return 0;
#endif
}

// /////////////////////////////////////////////////////////////

typedef unsigned char bytee;

bytee foo = 3;

struct Date {
    bytee nWeekDay : 3;  // 0..7    (3 bits)
    bytee nMonthDay : 5; // 0..31   (5 bits)
    // bytee : 0;            // Force alignment to next boundary.
    bytee nMonth : 4; // 0..12  (4 bits) (15 not 12 max)
    bytee : 0;        // Force alignment to next boundary.
    bytee nYear : 7;  // 0..100 (7 bits) (127 not 100 max)
};

Date dateHeld;

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
}

void _plus() {
    int a = pop();
    push(a + pop());
}

void _drop() {
    pop();
}

void _dup() {
    int a = pop();
    push(a);
    push(a);
}

void _swap() {
    int a = pop();
    int b = pop();
    push(a);
    push(b);
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
    Serial.println(" sanity check BB: ");
}

const bool DEBUG_flag_lcl = -1;

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
    if (DEBUG_flag_lcl == -1) {
        _printSanCheck();
    }
}

void blink() { /* n -- */
    int pin = pop();
    digitalWrite(pin, HIGH);
    delay(400);
    digitalWrite(pin, LOW);
    delay(400);
}

void strobeLeds() {
    for (uint8_t pin = pinMAX; pin > pinMIN - 1; pin--) {
        push(pin);
        blink();
    }
}

/***
 *
 *  D2 LED is D19 A5 sw8  #112299 'black' (deep blueish green)
 *  D3 LED is D18 A4 sw7  brown
 *  D4 LED is D17 A3 sw6  red
 *  D5 LED is D16 A2 sw5  orange
 *  D6 LED is D15 A1 sw4  yellow
 *  D7 LED is D14 A0 sw3  green wire on DIP switch sw3 / A0
 */

void readPin() { // ( pin -- pin state )
    _dup();
    uint8_t inPin = (uint8_t)pop();
    bool state = (bool)digitalRead(inPin);
    push((int)state);
}

// void doSubtractAbs() // ( inPin -- outPin )
// RAM:   [==        ]  17.6% (used 360 bytes from 2048 bytes)
// Flash: [=         ]   9.8% (used 3158 bytes from 32256 bytes)
// same ram footprint - likely the 'best' flash footprint at 3158 bytes

void mapPin() { // ( inPin -- outPin )
    uint8_t inPin = pop();
    uint8_t outPin = abs(inPin - 19) + 2;
    push(outPin);
}

void showDIPStates() {
    for (uint8_t inPin = inPinMAX; inPin > inPinMIN - 1; inPin--) {
        push((int)inPin);
        readPin();
        _swap();
        mapPin();
        uint8_t pin = (uint8_t)pop();
        bool state = (bool)pop();
        digitalWrite(pin, state);
    }
}

/* uno:2 is bit 2^0 LED (ersatz black LED) */

void ledsJob() {
    strobeLeds();
}

void switchStatesReport() {
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
    // ledsJob();
    stackJob();
    Serial.println("");
    Serial.println(" - - OOB marker - -");
    Serial.println("");
    // switchJob();
    // switchStatesReport();
    showDIPStates();
    _CRLF();
    _dotS();
    _CRLF();
    delay(400);
    // initExperiment();
}

// TODO validate pinMODE INPUT on D14 thru D19 'somehow'

void setupGPIO() {
    for (uint8_t pin = pinMAX; pin > pinMIN - 1; pin--) {
        pinMode(pin, OUTPUT);
    }
    // D19 down to D14:
    for (uint8_t pin = inPinMAX; pin > inPinMIN - 1; pin--) {
        pinMode(pin, INPUT);
    }
}

// const bool doDelay = -1;
const bool doDelay = 0;

void printSignonMsgs() {
    Serial.print(" build  ");
    Serial.print(" date: ");
    Serial.print(__DATE__);

    Serial.print("   time: ");
    Serial.print(__TIME__);

    Serial.print("z   line: ");
    Serial.println(__LINE__);
    Serial.println(TIME_STAMP);
    if (doDelay) {
        Serial.println();
        Serial.println(" long delay program identity check");
        delay(12123);
    }
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
