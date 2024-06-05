#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t test[4] = { 22, -44, -88, 44 };

    printf("%s", "\tuint8_t test[4] = { 22, -44, -88, 44 };\r\n");

    printf("%s", "\ttest[0]: ");
    printf("%b\r\n\r\n", test[0]);

    printf("\t%s", "test[1] holds -44:\r\n");
    printf("%s", "\ttest[1]: ");
    printf("%b\r\n", test[1]);

    int16_t p = (int16_t) test[1];
    int16_t q = 256 - p;
    int8_t  r = 212;
    int8_t  s = (int8_t) 212;
    int16_t t = 212;

    printf("\t      p: %b\r\n", p);
    printf("\t      q: %b\r\n", q);
    printf("\t      r: %b\r\n", r);
    printf("\t      s: %b\r\n", s);
    printf("\t      t: %b\r\n", t);

    printf("%s\n", "");
    for (int i = 0; i < 4; i++) {
        int16_t temp = (test[i] << 8 >> 8);
        printf("%d\n", temp);
    }
}

