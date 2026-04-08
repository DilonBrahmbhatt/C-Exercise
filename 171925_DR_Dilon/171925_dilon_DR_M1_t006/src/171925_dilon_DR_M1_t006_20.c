/*
Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
Author: Dilon Brahmbhatt
Created: 12 february, 2026
Modified: 12 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

#define TABSIZE 4

void detab_input_stream()
{
    int16_t ch;
     int16_t index = 1;
    int16_t space_count = 0;
  printf("press ctrl + D to escape the string\n");
    printf("Enter the String: ");
    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ')
        {
            space_count++;
            continue;
        }

        /* If space sequence ended */
        if (space_count > 0)
        {
            int16_t needed = (TABSIZE - ((index - 1) % TABSIZE)) % TABSIZE;
                space_count = needed;

            for (int i = 0; i < space_count; i++)
            {
                putchar(' ');
                index++;
            }

            space_count = 0;
        }

        if (ch == '\t')
        {
            int16_t spaces = (TABSIZE - ((index - 1) % TABSIZE)) % TABSIZE;;
            for (int i = 0; i < spaces; i++)
            {
                putchar(' ');
                index++;
            }
        }
        else
        {
            putchar(ch);
            if (ch == '\n')
                index = 1;
            else
                index++;
        }
    }
}


