/*
description: Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 30-03-2026
*/
#include<stdio.h>
#include<ctype.h>
#include "header.h"

int16_t *strend(char *string1, char *string2)
{
    char *s1;
    char *s2;

    if (*string2 == '\0')
        return 0;
   do {
        if (*string1 == *string2)
        {
            s1 = string1;
            s2 = string2;

            do{
                s1++;
                s2++;
            }while(*s1 == *s2);

            if (*s1 == '\0')
                return 1;
        }
        string1++;
    } while (*string1 != '\0');
return 0;
}

void strend_main()
{
    char str1[MAXLINE];
    char str2[MAXLINE];
    int16_t *result;

    clear_input_buffer();
    printf("Enter a string: ");
    mgetline(str1, MAXLINE);
    printf("Enter substring to search: ");
    mgetline(str2, MAXLINE);
    result = strend(str1, str2);
    if (result != NULL)
        printf("Substring found: %hd \n", result);
    else
        printf("Substring not found : %hd\n",result);
}
