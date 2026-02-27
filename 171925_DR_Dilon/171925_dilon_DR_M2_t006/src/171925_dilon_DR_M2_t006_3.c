#include <stdio.h>
#include <stdint.h>

void htoi() {
    char s[20];
    int16_t i = 0;
    int16_t value = 0;
    int16_t digit;

    printf("Enter hex value: ");
    scanf("%19s", s);

    // skip optional 0x or 0X
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    }

    for (; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            digit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            digit = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            digit = s[i] - 'A' + 10;
        }
        else {
            printf("Enter valid hex number\n");
            return;
        }

        value = value * 16 + digit;
    }

    printf("Decimal value = %d\n", value);
}
