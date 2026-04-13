/*
description: Modify the sort program to handle a -r flag,
                 which indicates sorting in reverse (decreasing) order.
                 Be sure that -r works with -n.
Author: Dilon Brahmbhatt
Created: 08 april, 2026
Modified: 09 april, 2026
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"

void myqsortReverse(char *v[], int left, int right,
             int16_t (*comp)(char *, char *), int16_t reverse)
{
    int16_t index, last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (index= left + 1; index <= right; index++)
    {
        int16_t result = comp(v[index], v[left]);

        if (reverse)
            result = -result;

        if (result < 0)
            swap(v, ++last, index);
    }

    swap(v, left, last);

    myqsortReverse(v, left, last - 1, comp, reverse);
    myqsortReverse(v, last + 1, right, comp, reverse);
}

int16_t str_cmp(char *s1, char *s2)
{
    return strcmp(s1, s2);
}

int16_t numcmp(char *s1, char *s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
void ReverseSorting(int16_t argc, char *argv[])
{   int16_t MAXLINES=100;
    int16_t nlines;
    char *lineptr[MAXLINES];
    int16_t numeric = 0;
    int16_t reverse = 0;

    for (int16_t index = 1; index < argc; index++)
    {
        if (strcmp(argv[index], "-n") == 0)
            numeric = 1;
        else if (strcmp(argv[index], "-r") == 0)
            reverse = 1;
	else if (strcmp(argv[index], "-rn") == 0 || strcmp(argv[index], "-nr") == 0) {
            numeric = 1;
            reverse = 1;}
    }
        clear_input_buffer();
    printf("Enter lines (Press ENTER on empty line to stop):\n");
        nlines = readlines(lineptr, MAXLINES);
    if (nlines >= 0)
    {
        if (numeric)
            myqsortReverse(lineptr, 0, nlines - 1, numcmp, reverse);
        else
            myqsortReverse(lineptr, 0, nlines - 1, str_cmp, reverse);

        printf("\nSorted Output:\n");
        writelines(lineptr, nlines);
    }
    else
    {
        printf("Error: input too big\n");
        return 1;
    }
}
