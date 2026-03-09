/*
discribtion: getch() and ungetch() is just pushing and popping the data from buffer which is array because we are assuming that there may be more than one character.
Author: Dilon Brahmbhatt
Created: 06 march, 2026
Modified: 06 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"

void EOF_handling()
{
    int16_t ch;
    int16_t start_of_line = 1;

    while ((ch = get_character()) != EOF)
    {
        if (start_of_line && ch != '\n')
        {
            putchar(ch);
            putchar('\n');
            start_of_line = 0;
        }

        if (ch == '\n')
        {
            start_of_line = 1;
        }
    }
pushback_character(ch);

    ch = get_character();
    if (ch == EOF)
        printf("EOF successfully pushed and retrieved from buffer.\n");
}
