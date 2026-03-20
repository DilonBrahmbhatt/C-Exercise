/*
description: Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
Author: Dilon Brhmbhatt
Created: 13 february, 2026
Modified: 13 february, 2026
*/

#include <stdio.h>
#include <stdint.h>
#define MAX 100
void reverse_line()
{
    int16_t ch;
    char char_arr[MAX];
    int index_arr[MAX];

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

    if (c_index > line_start)
    {
        index_arr[i_index++] = line_start;
        index_arr[i_index++] = c_index;
    }

    /* Reverse each line */
    for (int i = 0; i < i_index; i += 2)
    {
        int16_t start = index_arr[i];
        int16_t end   = index_arr[i + 1] - 1;

        while (start < end)
        {
            char temp = char_arr[start];
            char_arr[start] = char_arr[end];
            char_arr[end] = temp;

            start++;
            end--;
        }
    }

    printf("\nReversed Lines Output:\n");
    for (int i = 0; i < c_index; i++)
        putchar(char_arr[i]);
}
