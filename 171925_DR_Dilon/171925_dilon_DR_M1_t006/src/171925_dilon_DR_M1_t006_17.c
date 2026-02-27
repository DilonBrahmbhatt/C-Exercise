/*
Write a program to print all input lines that are longer than 8 characters.
Author: Dilon Brahmbhatt
Created: 09 february, 2026
Modified: 10 february, 2026
*/
#include<stdio.h>
#include<stdint.h>

#define MAX 100

void print_lines_longer_than_8()
{
    int16_t ch;
    int16_t char_arr[MAX];
    int16_t index_arr[MAX];

    int16_t c_index = 0;
    int16_t i_index = 0;
    int16_t line_start = 0;

    printf("ctrl + D to escape the string\n");
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

    /* If last line does NOT end with newline */
    if (c_index > line_start)
    {
        index_arr[i_index++] = line_start;
        index_arr[i_index++] = c_index;
    }

    printf("\nLines longer than 8 characters:\n");

    for (int i = 0; i < i_index; i += 2)
    {
        int len = index_arr[i + 1] - index_arr[i];

        if (len > 8)
        {
            for (int j = index_arr[i]; j < index_arr[i + 1]; j++)
            {
                if (char_arr[j] != '\n')
                    putchar(char_arr[j]);
            }
            putchar('\n');
        }
    }
}
