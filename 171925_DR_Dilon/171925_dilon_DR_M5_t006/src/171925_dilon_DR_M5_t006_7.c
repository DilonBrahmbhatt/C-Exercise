/*
description:Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage.
            How much faster is the program?
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 01-04-2026
*/
#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#define MAXLINES 100
#define MAXLEN 10000
/*
description: This function takes individual lines using mgetline function.
                 then use pointer array to points every line address.
author: Dilon Brahmbhatt
created date: 03-04-2026
modified date: 03-04-2026
*/
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    static char p[MAXLEN];
    char line[MAXLEN];
    nlines = 0;
    int i = 0;

    while ((len = mgetline(line, MAXLEN)) > 0)
    {
        if (len == 1)
            break;

          if (nlines >= maxlines || i + len >= MAXLEN)
            return -1;

        line[len - 1] = '\0';

        strcpy(&p[i], line);
        lineptr[nlines++] = &p[i];

        i += strlen(line) + 1;
    }

    return nlines;
}

/*
description: This function prints every line using pointer array.
author: Dilon Brahmbhatt
created date: 03-04-2026
modified date: 03-04-2026
*/
void writelines(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}
/*
description: This is a simple swapping function.
author: Dilon Brahmbhatt
created date: 03-04-2026
modified date: 03-04-2026
*/
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*
description: This is a sorting function which uses quick sort.
author:Dilon Brahmbhatt
created date: 03-04-2026
modified date: 03-04-2026
*/
void myqsort(char *v[], int left, int right)

{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    myqsort(v, left, last - 1);
    myqsort(v, last + 1, right);
}
/*
description: This function acts as main function and call readline writeline and sorting function.
author: Dilon Brahmbhatt
created date: 03-04-2026
modified date: 03-04-2026
*/
void ReadWriteLines()
{
clear_input_buffer();
char *lineptr[MAXLINES];
    int nlines;
    printf("Enter lines (Press ENTER on empty line to stop):\n");
    nlines = readlines(lineptr, MAXLINES);

    if (nlines < 0)
    {
        printf("Error: input too large\n");
        return;
    }
myqsort(lineptr, 0, nlines - 1);
    printf("\nStored Lines:\n");
    writelines(lineptr, nlines);
}


