/*
discribtion:Write the function strindex(s,t) which returns the position of the rightmost occurrence of t
            in s, or -1 if there is none.
Author: Dilon Brahmbhatt
Created: 27 february, 2026
Modified: 27 february, 2026
*/

#include<stdio.h>
#include<stdint.h>
#include<string.h>

void strindex_main() {
    char s[100], t[100];
    int8_t s_index = 0;
    int8_t t_index = 0;
    int16_t ch;
    int8_t i, j;

    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("Enter the main string (s): ");
    while ((ch = getchar()) != '\n' && ch != EOF && s_index < 99)
    {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ('a' - 'A');
        }
        s[s_index] = ch;
        s_index++;
    }
    s[s_index] = '\0';

    printf("Enter the search string (t): ");
    while ((ch = getchar()) != '\n' && ch != EOF && t_index < 99)
    {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ('a' - 'A');
        }
        t[t_index] = ch;
        t_index++;
    }
    t[t_index] = '\0';

    // find last occurrence of t in s
    for (i = s_index - t_index; i >= 0; i--)
    {
        for (j = 0; t[j] != '\0'; j++)
        {
            if (s[i + j] != t[j])
                break;
        }

        if (t[j] == '\0') {
            printf("Last occurrence index: %d\n", ++i);
            return;
        }
    }

    printf("Substring not found\n");
}


