/*
Write a program to count blanks, tabs, and newlines.
Author: Dilon Brahmbhatt
Created: 09 february, 2026
Modified: 09 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

void count_blanks_tabs_newlines()
{
   int16_t c;
   uint8_t blanks = 0, tabs = 0, newlines = -1;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            blanks++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n')
            newlines++;
    }

    printf("\nBlanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

}
