/*
description: Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.
Author: Ved vyas
Created: 26 february, 2026
Modified: 26 february, 2026
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include "header.h"
#define MAX_LEN 100

void itoa_Min_Width(int32_t number, char resultStr[], int32_t Min_width)
{
    int16_t index = 0;
    int32_t originalSign = number;

    if (number < 0)
        number = -(number + 1);   // shift to avoid overflow

    do
    {
        resultStr[index++] = (number % 10) + '0';
    } while ((number /= 10) > 0);
 
    if (originalSign < 0){
        resultStr[index++] = '-';
}
 
     while (index < Min_width){
        resultStr[index++] = '*';
}
    resultStr[index] = '\0';
    reverse_string(resultStr);
 
    if (originalSign < 0)
        resultStr[strlen(resultStr) - 1]++;   // fix last digit
}
 
void Min_field_width()
{
    char outputString[MAX_LEN];
    int32_t inputNumber;
        int32_t width;
    printf("Digit: ");
    scanf("%d", &inputNumber);
printf("Min Field width: ");
    scanf("%d", &width);
    itoa_Min_Width(inputNumber, outputString, width);
 
    printf("Converted string: %s\n", outputString);
}
