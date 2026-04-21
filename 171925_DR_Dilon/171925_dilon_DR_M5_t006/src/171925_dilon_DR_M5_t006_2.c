/*
description: As written, getint treats a + or - not followed by a digit as a valid representation of zero.
                Fix it to push such a character back on the input.
Author: Dilon Brahmbhatt
Created: 27 march, 2026
Modified: 27 march, 2026
*/

#include<stdio.h>
#include<ctype.h>
#include "header.h"
#define SIZE 1000

int16_t getfloat(float *);

void validFloatRPN()
{
    int n;
    float array[SIZE];
        printf("enter a number:");
    for(n=0;n<SIZE && getfloat(&array[n]) !=EOF;n++)
    {
        for(;n>=0;n--)
            printf("%f\n",array[n]);
    }

}

int16_t getfloat(float *pn) {
    int8_t c, sign;
    float power;

    while (isspace(c = get_character()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        pushback_character(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = get_character();

    for (*pn = 0.0; isdigit(c); c = get_character())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = get_character();
    for (power = 1.0; isdigit(c); c = get_character()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn *= sign / power;
    if (c != EOF)
        pushback_character(c);
    return c;
}
