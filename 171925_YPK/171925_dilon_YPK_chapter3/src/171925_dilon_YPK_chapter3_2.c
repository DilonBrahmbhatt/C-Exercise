/*
        description: Write a function xstrstr( ) that will scan a string for the
        occurrence of a given sub-string. The prototype of the
        function would be:

        char * xstrstr ( char *string1, char *string2) ;

        The function should return a pointer to the element in string1
        where string2 begins. If string2 doesn't occur in string1 then
        xstrstr( ) should return a NULL.

        For example, if string1 is "somewhere over the rainbow", and
        string2 is "over" then xstrstr( ) should return address of 'o'
        in string1.
Author: Dilon Brahmbhatt
Created: 18 march, 2026
Modified: 18 march, 2026
*/

#include <stdio.h>
#include "../inc/YPK.h"
#define MAX 100

char *xstr(char *string1, char *string2)
{
    char *s1;
    char *s2;

    if (*string2 == '\0')
        return string1;

    while (*string1 != '\0')
    {
        if (*string1 == *string2)
        {
            s1 = string1;
            s2 = string2;

            while (*s2 != '\0' && *s1 == *s2)
            {
                s1++;
                s2++;
            }

            if (*s2 == '\0')
                return string1;
        }
        string1++;
    }
}
void find_substring()
{
    char str1[MAX];
    char str2[MAX];
    char *result;
    clear_input_buffer();
    printf("Enter a string: ");
    mgetline(str1, MAX);
    printf("Enter substring to search: ");
    mgetline(str2, MAX);
    result = xstr(str1, str2);
    if (result != NULL)
        printf("Substring found at position: %ld\n", result - str1);
    else
        printf("Substring not found\n");
}
