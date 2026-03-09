/*
description: Write a recursive version of the function reverse(s), which reverses the string s in place.
Author :Dilon Brahmbhatt
Created: 08 march, 2026
Modified: 08 march, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "header.h"
#include <string.h>

void reverse_string_recursion(char str[], int16_t startIndex, int16_t endIndex)
{
    char tempChar;

    if (startIndex >= endIndex)
        return;

    tempChar = str[startIndex];
    str[startIndex] = str[endIndex];
    str[endIndex] = tempChar;

    reverse_string_recursion(str, startIndex + 1, endIndex - 1);
}

void reverse_string_using_recursion()
{
     char str[MAXLINE];
      int16_t len;
while (1)
    {
       int16_t tokenType = getchar();
        if (tokenType == '\n')
            break;
    }
    printf("Enter string: ");
    len = mgetline(str, MAXLINE);

    if (len > 0 && str[len-1] == '\n')
        str[len-1] = '\0';   // remove newline
    int16_t startIndex = 0;
    int16_t endIndex = strlen(str) - 1;

    reverse_string_recursion(str, startIndex, endIndex);

    printf("Reversed string: %s\n", str);

}
