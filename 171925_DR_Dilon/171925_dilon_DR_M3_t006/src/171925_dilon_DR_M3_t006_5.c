/*
description: Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
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

void itob(int32_t number, char resultStr[], int32_t base)
{
    int32_t index, remainder, originalSign;

    if ((originalSign = number) < 0)
        number = -(number + 1);

    index = 0;

    do
    {
        remainder = number % base;

        if (remainder <= 9)
        {
          resultStr[index++] = remainder + '0';
                }
        else
        {
          resultStr[index++] = remainder + 'A' - 10;
                }

    } while ((number /= base) > 0);

    if (originalSign < 0)
        resultStr[index++] = '-';

    resultStr[index] = '\0';
 
    reverse_string(resultStr);
}
 
void Digit_and_Base()
{
    int32_t inputNumber, conversionBase;
    char outputString[MAX_LEN];
        printf("Digit: ");
        scanf("%d",&inputNumber);
        printf("Base: ");
        scanf("%d",&conversionBase);
if(conversionBase < 0){
printf("Enter a valid base value \n");
}
else{
itob(inputNumber, outputString, conversionBase);
printf("Ans: %s\n", outputString);
}
}
