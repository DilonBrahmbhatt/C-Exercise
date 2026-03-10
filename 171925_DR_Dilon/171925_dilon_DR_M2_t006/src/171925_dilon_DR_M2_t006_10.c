/*
description: Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression
instead of if-else.
Author: Dilon Brahmbhatt
Created: 24 february, 2026
Modified: 24 february, 2026

*/

#include <stdio.h>
#include <stdint.h>
char lower(char Ichar)

{

    return (Ichar >= 'A' && Ichar <= 'Z') ? (Ichar + 'a' - 'A') : Ichar;

}
 
void Uper_to_Lower()

{
  int16_t ch;
 
printf("\nEnter the String: ");

    while ((ch = getchar()) != EOF )

    {

        putchar(lower(ch));

    }

printf("\n");

}
 
