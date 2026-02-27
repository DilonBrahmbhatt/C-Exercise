/*
Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
Author: Dilon Brahmbhatt
Created: 11 february, 2026
Modified: 11 february, 2026
*/
#include <stdio.h>
#include <stdint.h>
#define MAX_ASCII 256

void plot_word_length_histogram()
{
    int16_t counts[MAX_ASCII] = {0};
    int16_t c;

    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < MAX_ASCII) {
            counts[c]++;
        }
    }
    counts[10]--;
    for (int i = 0; i < MAX_ASCII; i++) {
        if (counts[i] > 0) {
            if (i == '\n') {
              printf("\\n ");
             }
            else if (i == '\t') {
              printf("\\t ");
             }
            else if (i == ' ') {
              printf("\\s ");
             }
            else {
              printf("%c  ", (char)i);
             }
            for (int j = 0; j < counts[i]; j++) {
              printf("*");
            }
            printf("\n");
        }
    }
}
