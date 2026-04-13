/*
Description: Write the program tail, which prints the last n lines of its input. By default,
                 n is set to 10, let us say, but it can be changed by an optional argument so that tail -n
                prints the last n lines. The program should behave rationally no matter how unreasonable
                the input or the value of n. Write the program so it makes the best use of available storage;
                 lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size.
Author: Dilon Brahmbhatt
Created: 07 april, 2026
Modified: 07 april, 2026
*/

#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "header.h"

/*
description: This is a custom writeline function design to print last n lines
Author: Dilon Brahmhatt
Created: 08 april, 2026
Modified: 08 april, 2026
*/
void writelines_tail(char *lineptr[], int16_t start, int16_t end)
{
    for (int16_t index = start; index < end; index++)
        printf("%s\n", lineptr[index]);
}

/*
description: This function act as a main function and calls readlines() and writeline() functions.
Author: Dilon Brahmhatt
Created: 08 april, 2026
Modified: 08 april, 2026
*/
void ReadLineTail(int16_t argc, char *argv[])
{
        int16_t num = 10;
    char *lineptr[MAXLINES];
    int16_t nlines;

    if (argc > 1)
    {
        num = abs(atoi(argv[1]));
    }
   clear_input_buffer();
    printf("Enter lines (Press ENTER on empty line to stop):\n");
   nlines = readlines(lineptr, MAXLINES);

    if (nlines < 0)
    {
        printf("Entered Input is Very large. \n");
        return;
    }
    if (num > nlines)
        num = nlines;
        printf("Last %d Lines are:\n",num);
    writelines_tail(lineptr, nlines - num, nlines);
}
