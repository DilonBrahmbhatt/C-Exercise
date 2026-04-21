/*
description:Add the -d (``directory order'') option, which makes comparisons only on letters,
            numbers and blanks. Make sure it works in conjunction with -f.
Author: Dilon Brahmbhatt
Created: 09 april, 2026
Modified: 09 april, 2026
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include "header.h"

/*
Description: This is a function FoldingAndDirectoryOrder(int16_t argc, char *argv[])
        which perform folding and directory ordered sorting using myqsort fucntion used in q7.
Author: Dilon Brahmbhatt
Created: 09 april, 2026
Modified: 09 april, 2026
*/
void FoldingAndDirectoryOrder(int16_t argc, char *argv[])
{
    int16_t nlines;
    int8_t MAXLINES=100;
    char *lineptr[MAXLINES];
    char *lowerptr[MAXLINES];

    int16_t fold = 0;
    int16_t dir = 0;

    for (int index = 1; index < argc; index++) {
        if (strcmp(argv[index], "-f") == 0)
            fold = 1;
        else if (strcmp(argv[index], "-d") == 0)
            dir = 1;
        else if (strcmp(argv[index], "-fd") == 0 || strcmp(argv[index], "-df") == 0) {
            fold = 1;
            dir = 1;
        }
    }

    clear_input_buffer();

    printf("Enter lines (Press ENTER on empty line to stop):\n");
    nlines = readlines(lineptr, MAXLINES);

    if (nlines < 0) {
        printf("input too big\n");
        return;
    }

    for (int index = 0; index < nlines; index++) {
        lowerptr[index] = strdup(lineptr[index]);

        int indexk = 0;

        for (int indexj = 0; lineptr[index][indexj]; indexj++) {
            char c = lineptr[index][indexj];

            if (dir) {
                if (!isalnum(c) && c != ' ')
                    continue;
            }
            if (fold)
                c = tolower(c);

            lowerptr[index][indexk++] = c;
        }

        lowerptr[index][indexk] = '\0';
    }

    if (fold || dir)
        myqsort_fold(lineptr, lowerptr, 0, nlines - 1);
    else
        myqsort(lineptr, 0, nlines - 1);

    printf("\nSorted Output:\n");
    writelines(lineptr, nlines);

    for (int16_t index = 0; index < nlines; index++) {
        free(lowerptr[index]);
    }
}
