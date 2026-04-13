/*
description: Add the option -f to fold upper and lower case together,
                 so that case distinctions are not made during sorting;
                 for example, a and A compare equal.
Author: Dilon Brahmbhatt
Created: 09 april, 2026
Modified: 09 april, 2026
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"
/*
Description: This function uses quicksort and for swaping,
         it passed both the array one is lower cased and one is original.
Author:Dilon Brahmbhatt
Created: 09 april, 2026
Modified: 09 april, 2026
*/
void myqsort_fold(char *v[], char *lowv[], int16_t left, int16_t right)
{
    int16_t index, last;

    if (left >= right)
        return;

    swap_both(v, lowv, left, (left + right) / 2);
    last = left;

    for (index = left + 1; index <= right; index++)
    {
        if (strcmp(lowv[index], lowv[left]) < 0)
            swap_both(v, lowv, ++last, index);
    }
     swap_both(v, lowv, left, last);

    myqsort_fold(v, lowv, left, last - 1);
    myqsort_fold(v, lowv, last + 1, right);
}
/*
Description: This function swaps according to the sorting algorithm.
Author: Dilon Brahmbhatt
Created: 09 april, 2026
Modified: 09 april, 2026
*/
void swap_both(char *v[], char *lowv[], int16_t indexi, int16_t indexj)
{
            char *temp;

        temp = v[indexi];
        v[indexi] = v[indexj];
        v[indexj] = temp;

        temp = lowv[indexi];
        lowv[indexi] = lowv[indexj];
        lowv[indexj] = temp;
}

/*
Description: This function acts as main function for folding program.
         which use linewrite myqsort_both functions for taking line and sort them.
Author: Dilon Brahmbhatt
Created: 09 april, 2026
Modified: 09 april, 2026
*/
void FoldingAlphabets(int16_t argc, char *argv[])
{   int8_t MAXLINES=100;
    int16_t nlines;
    char *lineptr[MAXLINES];
        char *lowerptr[MAXLINES];
        int16_t fold = 0;

    // Check for -f option
    if (argc > 1 && strcmp(argv[1], "-f") == 0)
        fold = 1;

    clear_input_buffer();

    printf("Enter lines (Press ENTER on empty line to stop):\n");
    nlines = readlines(lineptr, MAXLINES);
        for (int8_t index = 0; index < nlines; index++) {
    lowerptr[index] = strdup(lineptr[index]);

    for (int8_t indexj = 0; lowerptr[index][indexj]; indexj++) {
        lowerptr[index][indexj] = tolower(lowerptr[index][indexj]);
    }
}
    if (nlines >= 0)
    {
        if (fold)
        myqsort_fold(lineptr, lowerptr, 0, nlines - 1);
        else
        myqsort(lineptr, 0, nlines - 1);

        printf("\nSorted Output:\n");
        writelines(lineptr, nlines);
    }
    else
    {
        printf("input too big\n");
    }
}
