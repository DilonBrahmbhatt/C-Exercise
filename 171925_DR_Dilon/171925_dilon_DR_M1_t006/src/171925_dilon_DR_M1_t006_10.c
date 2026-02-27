/*
Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b,
and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
Author: Dilon Brahmbhatt
Created: 10 february, 2026
Modified: 10 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

void print_visible_control_chars()
{
int16_t ch;
    char ans[200];
    int16_t length = 0;

    while ((ch = getchar()) != EOF && length < 198) {
        if (ch == '\t') {
            ans[length++] = '\\';
            ans[length++] = 't';
        }
        else if (ch == '\b') {
            ans[length++] = '\\';
            ans[length++] = 'b';
        }
        else if (ch == '\\') {
            ans[length++] = '\\';
            ans[length++] = '\\';
        }
        else {
            ans[length++] = ch;
        }
    }

    ans[length] = '\0';
    printf("\n%s\n", ans);
}
