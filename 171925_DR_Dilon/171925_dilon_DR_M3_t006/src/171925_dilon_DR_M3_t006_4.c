/*
description:In a two's complement number representation, our version of itoa does not handle the largest negative
            number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that
            value correctly, regardless of the machine on which it runs.
Author: Dilon Brahmbhatt
Created: 26 february, 2026
Modified: 26 february, 2026
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "header.h"
#include <stdint.h>
#define MAX_LEN 100

void itoa(int number, char resultStr[])
{
    int index = 0;
    int originalSign = number;
    if (number < 0)

        number = -(number + 1);   // shift to avoid overflow
    do
    {
        resultStr[index++] = (number % 10) + '0';
    } while ((number /= 10) > 0);

    if (originalSign < 0)
        resultStr[index++] = '-';

    resultStr[index] = '\0';
    reverse_string(resultStr);

    if (originalSign < 0)
        resultStr[strlen(resultStr) - 1]++;   // fix last digit
}

void input_and_convert()
{
    char outputString[MAX_LEN];
    int inputNumber;

    printf("Enter number: ");
    scanf("%d", &inputNumber);
    itoa(inputNumber, outputString);
    printf("Converted string: %s\n", outputString);

}


