/*
description: Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)
Author: Dilon Brahmbhatt
Created: 20 february, 2026
Modified: 20 february, 2026
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
 
void any() {
    char s1[1000];
    bool lookup[256] = {false};
    uint16_t input_idx = 0;
 
    int16_t c;
    int16_t first_occurrence = -1;
while (1)
    {
        c = getchar();
        if (c == '\n')
            break;
    }
 
    printf("Enter string 1: ");
    while ((c = getchar()) != '\n' && c != EOF && input_idx < 999) {
        s1[input_idx++] = (char)c;
    }
    s1[input_idx] = '\0';
 
    printf("Enter string 2: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        lookup[(uint8_t)c] = true;
    }
 
    for (uint16_t i = 0; s1[i] != '\0'; i++) {
        if (lookup[(uint8_t)s1[i]]) {
            first_occurrence = i ; // Indexing starts from 1
            break;
        }
    }
 
    // 4. Output results based on whether a match was found
    if (first_occurrence != -1) {
        printf("Duplicate character is found at %d in string 1\n", first_occurrence);
    } else {
        printf("No duplicate characters found.\n");
    }
}
