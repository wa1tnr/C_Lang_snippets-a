// Sat 15 Jun 23:17:53 UTC 2024

#include <Arduino.h>

extern char buffer[64];
extern void print_me();
extern void print_cr();

#ifdef __cplusplus
extern "C" {
#endif

unsigned int *rsp;

void print_rsp_addr_val(uint8_t index) {
    unsigned int *rsp_rs = &rsp[index];
    int address = (unsigned int)rsp_rs;
    snprintf(buffer, sizeof(buffer), "\trrufus_rsp[%d]: %12X: ", index,
             address);
    print_me();

    int rq = rsp[index];
    snprintf(buffer, sizeof(buffer), "%8X", rq);
    print_me();
    print_cr();
}
#ifdef __cplusplus
}
#endif
// end.
