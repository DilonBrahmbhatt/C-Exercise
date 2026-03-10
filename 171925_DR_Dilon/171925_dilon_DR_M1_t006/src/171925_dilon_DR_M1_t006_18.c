/*
Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
Author: Dilon Brahmbhatt
Created: 13 february, 2026
Modified: 13 february, 2026
*/

#include <stdio.h>
#include <stdint.h>
#define MAX 100   // total character storage

void remove_trailing_blanks_tabs()
{
    int16_t ch;
    int16_t char_arr[MAX];
    int16_t index_arr[MAX];
 
    int16_t c_index = 0;
    int16_t i_index = 0;
    int16_t line_start = 0;

    printf("press ctrl + D to escape the string\n");
    printf("Enter the String: ");

    while ((ch = getchar()) != EOF)
    {
        char_arr[c_index++] = ch;

        if (ch == '\n')
        {
            index_arr[i_index++] = line_start;
            index_arr[i_index++] = c_index - 1;
            line_start = c_index;
        }
    }

    /* Handle last line if no newline */
    if (c_index > line_start)
    {
        index_arr[i_index++] = line_start;
        index_arr[i_index++] = c_index;
    }

    printf("\nOutput:\n");

    for (int i = 0; i < i_index; i += 2)
    {
        int16_t start = index_arr[i];
        int16_t end   = index_arr[i + 1];

        /* Remove trailing spaces and tabs */
        while (end > start && (char_arr[end - 1] == ' ' || char_arr[end - 1] == '\t'))
        {
            end--;
        }

        /* Print only non-empty lines */
        if (end > start)
        {
            for (int j = start; j < end; j++)
                putchar(char_arr[j]);

            putchar('\n');
        }
    }
}
