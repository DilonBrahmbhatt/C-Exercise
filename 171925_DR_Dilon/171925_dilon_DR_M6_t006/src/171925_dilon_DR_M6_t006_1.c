/*
description: Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control lines.
Author: Dilon Brahmbhatt
Created: 16 April, 2026
Modified: 16 April, 2026
*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "header.h"
void FrequecyOfKeywords() {
    int16_t n;
    char word[MAXWORD];
clear_input_buffer();
printf("Enter you lines: \n");
    while (mygetword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
printf("Keyword counts: \n");
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
}
