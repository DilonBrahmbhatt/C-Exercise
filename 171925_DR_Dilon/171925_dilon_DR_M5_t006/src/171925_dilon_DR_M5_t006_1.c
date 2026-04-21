/*
description: As written, getint treats a + or - not followed by a digit as a valid representation of zero.
                Fix it to push such a character back on the input.
Author: Dilon Brahmbhatt
Created: 27 march, 2026
Modified: 27 march, 2026
*/

#include<stdio.h>
#include<ctype.h>
#include<stdint.h>
#include"header.h"
#define SIZE 1000

int16_t getint_updated(int16_t *pn) {
    int8_t c, sign;
    while (isspace(c = get_character()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        pushback_character(c); /* it's not a number */
        printf("invalid Entry!!");
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = get_character();
    if (!isdigit(c))
        {
        printf("invalid Entry!!");
         return 0;
}
    for (*pn = 0; isdigit(c); c = get_character())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        pushback_character(c);
    return 1;
}
void validNumberRPN() {
    int16_t n = 0, array[SIZE];
    int16_t status;
    printf("Enter numbers (Ctrl+D or EOF to stop):\n");
    while (n < SIZE) {
        printf("[%d] Enter a number: ", n);
        status = getint_updated(&array[n]);
        if (status == EOF) {
            break;
        } else if (status == 0) {
     continue;
        } else {
            printf("Stored: %d\n", array[n]);
            n++;
        }
    }
    printf("\nStored Numbers");
    for (int s = 0; s < n; s++) {
        printf("\nIndex %d: %d", s, array[s]);
    }
}

