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
        return -1; /* -1 will end the program directly */
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = get_character();

    if (!isdigit(c))
        return 0;
    for (*pn = 0; isdigit(c); c = get_character())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        pushback_character(c);

    return c;
}

void validNumberRPN()
{
    int16_t n,s,array[SIZE];
    printf("enter a number:");
    for(n=0;n<SIZE && getint_updated(&array[n]) !=EOF; n++){
        printf("storing in n = %d, getint %d\n", n, array[n]);
    }
    printf("storing in n = %d, getint %d\n", n, array[n]);
    for(s=0;s<=n; s++)
        printf("%d",array[s]);
}
