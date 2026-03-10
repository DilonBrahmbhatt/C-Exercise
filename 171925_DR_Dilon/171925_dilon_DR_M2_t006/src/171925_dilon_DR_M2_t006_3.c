/*
description:Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into
            its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
Author: Dilon Brahmbhatt
Created: 20 february, 2026
Modified: 20 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

void htoi() {
    char s[20];
    int16_t index = 0;
    int16_t value = 0;
    int16_t digit;

    printf("Enter hex value: ");
    scanf("%19s", s);

    // skip optional 0x or 0X
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        index = 2;
    }

    for (; s[index] != '\0'; index++) {
        if (s[index] >= '0' && s[index] <= '9') {
            digit = s[index] - '0';
        }
        else if (s[index] >= 'a' && s[index] <= 'f') {
            digit = s[index] - 'a' + 10;
        }
        else if (s[index] >= 'A' && s[index] <= 'F') {
            digit = s[index] - 'A' + 10;
        }
        else {
            printf("Enter valid hex number\n");
            return;
        }

        value = value * 16 + digit;
    }

    printf("Decimal value = %d\n", value);
}
