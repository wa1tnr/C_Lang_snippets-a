/* gcc amd64 Linux */

/* dash_asked-aa.c */

#include <stdio.h>
#include <stdint.h>

int main() {
    // make required #include statements here
    int16_t seven[] = { 212, 212, 212, 212, 212, 212, 212};
    printf("%s", "\tseven[0]: ");
    printf("%b\r\n\r\n", seven[0]);
    printf("%s", "\tseven[1]: ");
    printf("%b\r\n\r\n", seven[1]);
    printf("%s", "\tseven[2]: ");
    printf("%b\r\n\r\n", seven[2]);
}
