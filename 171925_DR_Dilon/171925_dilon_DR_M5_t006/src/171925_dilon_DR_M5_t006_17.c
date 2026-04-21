/*
description: Task is Identify and sort specific fields within each line.
                Apply different sorting options to each field independently.
Author: Dilon Brahmbhatt
Created: 10 april, 2026
Modified: 10 april, 2026
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include "header.h"

/* remove non-alphanumeric + convert to lowercase */
void clean_string(char *src, char *dest)
{
    int i = 0, j = 0;
    while (src[i]) {
        if (isalnum(src[i]) || src[i] == ' ') {
            dest[j++] = tolower(src[i]); // -df
        }
        i++;
    }
    dest[j] = '\0';
}
/* extract category and page */
void extract_fields(char *line, char *category, int *page)
{
    sscanf(line, "Category: %[^,], Page: %d", category, page);
}
/* comparison function */
int compare_lines(char *s1, char *s2, int fold, int dir, int numeric, int key)
{
    char cat1[100], cat2[100];
    char clean1[100], clean2[100];
    int page1, page2;
    extract_fields(s1, cat1, &page1);
    extract_fields(s2, cat2, &page2);
    if (dir || fold) {
        clean_string(cat1, clean1);
        clean_string(cat2, clean2);
    } else {
        strcpy(clean1, cat1);
        strcpy(clean2, cat2);
    }

if (key == 1) {
        char clean1[100], clean2[100];
        if (dir || fold) {
             clean_string(cat1, clean1);
            clean_string(cat2, clean2);
           } else {
             strcpy(clean1, cat1);
            strcpy(clean2, cat2);
        }
        int cmp = (fold) ? strcasecmp(clean1, clean2) : strcmp(clean1, clean2);
        return cmp;
    }
    else if (key == 2) {
        if (numeric)
            return page1 - page2;
        else {
            char p1[20], p2[20];
            sprintf(p1, "%d", page1);
            sprintf(p2, "%d", page2);
            return strcmp(p1, p2);
        }
    }
    return 0;
}
/* quicksort using custom compare */
void myqsort_SortCategoryPage(char *v[], int left, int right,int fold, int dir, int numeric, int key)
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (compare_lines(v[i], v[left], fold, dir, numeric,key) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    myqsort_SortCategoryPage(v, left, last - 1, fold, dir, numeric, key);
    myqsort_SortCategoryPage(v, last + 1, right, fold, dir, numeric, key);
}
/* main function */
void SortCategoryPage(int argc, char *argv[])
{
    int16_t nlines;
    int8_t MAXLINES=100;
    char *lineptr[MAXLINES];
    int16_t fold = 0;
    int16_t dir = 0;
    int16_t numeric = 0;
    int16_t key = 1;
    for (int16_t i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0)
            fold = 1;
        else if (strcmp(argv[i], "-d") == 0)
            dir = 1;
        else if (strcmp(argv[i], "-n") == 0)
            numeric = 1;
        else if (strcmp(argv[i], "-df") == 0 || strcmp(argv[i], "-fd") == 0) {
            fold = 1;
            dir = 1;
        }
        else if (strncmp(argv[i], "-k", 2) == 0) {
            key = atoi(&argv[i][2]);      }
    }
    clear_input_buffer();
    printf("Enter lines:\n");
    nlines = readlines(lineptr, MAXLINES);
    if (nlines < 0) {
        printf("input too big\n");
        return;
    }
    myqsort_SortCategoryPage(lineptr, 0, nlines - 1,
                             fold, dir, numeric, key);
    printf("\nSorted Output:\n");
    writelines(lineptr, nlines);
}
