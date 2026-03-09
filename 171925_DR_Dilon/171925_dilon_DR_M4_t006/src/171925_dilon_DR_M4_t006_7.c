/*
description: Write a routine ungets(s) that will push back an entire string onto the input.
                 Should ungets know about buf and bufp, or should it just use ungetch?
Author : Ved Vyas
Created: 06 march, 2026
Modified: 06 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"
#define MAXLINE 100

void ungets_main() {
    char line[MAXLINE];
    int16_t ch;

    mgetline(line, MAXLINE);
    ungets(line);

    while ((ch = get_character()) != EOF)
        putchar(ch);
printf("\n");
}
