/*
description: The macro concept is used where we want to substitute some part of code with a constant.
Author : Dilon Brahmbhatt
Created: 09 march, 2026
Modified: 09 march, 2026
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "header.h"
 
#define swap(type, firstValue, secondValue) \
{                                           \
    type temporary;                         \
    temporary = firstValue;                 \
    firstValue = secondValue;               \
    secondValue = temporary;                \
}
 
void macro_swap()
{
    char a = 'X';
    char b = 'Y';
 
    printf("Before swap: a = %c, b = %c\n", a, b);
 
    swap(char, a, b);
 
    printf("After swap:  a = %c, b = %c\n", a, b);
 
}
