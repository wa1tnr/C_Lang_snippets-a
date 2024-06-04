#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t test[4] = { 22, -44, -88, 44 };

    for (int i = 0; i < 4; i++) {
        int16_t temp = (test[i] << 8 >> 8);
        printf("%d\n", temp);
    }
}

