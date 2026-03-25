/*
description: this file contains common functions.
Author: Dilon Brahmbhatt
Created: 27 february, 2026
Modified: 08 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include "../inc/YPK.h"

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int16_t mgetline(char s[], int16_t lim)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
 
    s[i] = '\0';
    return i;
}
