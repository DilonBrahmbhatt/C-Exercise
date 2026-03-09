/*
description: Adapt the ideas of printd to write a recursive version of itoa; that is,
                convert an integer into a string by calling a recursive routine.
Author : Ved Vyas
Created: 08 march, 2026
Modified: 08 march, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "header.h"

void itoa_recursive(int16_t number, char resultStr[], int16_t *index)
{
    if (number / 10){

        itoa_recursive(number / 10, resultStr, index);

}
    resultStr[(*index)++] = abs(number % 10) + '0';
}

void itoa_using_recursion()
{
    char outputString[100];
    int16_t inputNumber;

    printf("Enter number: ");
    scanf("%hd", &inputNumber);

    int16_t index = 0;

    if (inputNumber < 0)
        outputString[index++] = '-';

    itoa_recursive(inputNumber, outputString, &index);

    outputString[index] = '\0';

    printf("Converted string: %s\n", outputString);

}
