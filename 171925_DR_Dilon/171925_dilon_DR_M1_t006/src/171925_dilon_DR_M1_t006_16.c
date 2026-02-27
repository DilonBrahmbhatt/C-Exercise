/*
Revise the main routine of the longest-line program so it will correctly print the length of
arbitrary long input lines, and as much as possible of the text.
Author: Dilon Brahmbhatt
Created: 11 february, 2026
Modified: 12 february, 2026
*/
#include <stdio.h>
#include <stdint.h>
#define MAX 100
void find_longest_line()
{
int16_t ch;
    int16_t char_arr[MAX];

    int16_t current_index = 0;
    int16_t current_start = 0;

    int16_t max_len = 0;
    int16_t max_start = 0;

    printf("press ctrl + D to escape the string\n");
    printf("Enter the String: ");

    while ((ch = getchar()) != EOF)
    {
        char_arr[current_index++] = ch;

        if (ch == '\n')
        {
            int16_t line_len = current_index - current_start;

            if (line_len > max_len)
            {
                max_len = line_len;
                max_start = current_start;
            }

            current_start = current_index;   // next line start
        }
    }

    /* If last line does NOT end with newline */
    if (current_index > current_start)
    {
        int16_t line_len = current_index - current_start;

        if (line_len > max_len)
        {
            max_len = line_len;
            max_start = current_start;
        }
    }

    printf("\nLongest line is:\n");

    for (int16_t i = max_start; i < max_start + max_len; i++)
    {
        putchar(char_arr[i]);
    }

    printf("Length: %hd\n", max_len);
}
