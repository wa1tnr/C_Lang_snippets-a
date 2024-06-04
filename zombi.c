#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t test[4] = { 22, -44, -88, 44 };

    printf("%s", "\tuint8_t test[4] = { 22, -44, -88, 44 };\r\n");

    printf("%s", "\ttest[0]: ");
    printf("%b", test[0]);

    printf("%s", "\ttest[1]: ");
    printf("%b", test[1]);

    printf("%s\n", "");
    for (int i = 0; i < 4; i++) {
        int16_t temp = (test[i] << 8 >> 8);
        printf("%d\n", temp);
    }
}

