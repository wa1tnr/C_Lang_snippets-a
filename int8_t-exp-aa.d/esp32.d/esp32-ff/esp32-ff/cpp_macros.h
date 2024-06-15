/* cpp_macros.h*/

#define print_faked()                                                          \
    print_me();                                                                \
    buf_ptr = (char *)&buffer;                                                 \
    pushed = (int)buf_ptr;                                                     \
    push(pushed - POFFSET);                                                    \
    rdumps();                                                                  \
    tossed = pop();                                                            \
    if (tossed == -715)                                                        \
        Serial.println("NEVER");

#define print_faked_cr()                                                       \
    print_me();                                                                \
    print_cr();                                                                \
    buf_ptr = (char *)&buffer;                                                 \
    pushed = (int)buf_ptr;                                                     \
    push(pushed - POFFSET);                                                    \
    rdumps();                                                                  \
    tossed = pop();                                                            \
    if (tossed == -715)                                                        \
        Serial.println("NEVER_CR");

/* end. */
