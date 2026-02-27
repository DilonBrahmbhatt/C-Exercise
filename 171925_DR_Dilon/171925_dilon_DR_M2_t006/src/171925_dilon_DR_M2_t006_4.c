/*
description: Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.
Author: Dilon Brahmbhatt
Created: 20 february, 2026
Modified: 20 february, 2026
*/
 
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
 
void squeeze() {
    char s1[1000];
    bool should_remove[256] = {false};
    // Most optimized index type for 1000 characters (2 bytes)
    uint16_t input_index = 0;
    uint16_t output_index = 0;
    int16_t c;
  while (1)
    {
        c = getchar();
        if (c == '\n')
            break;
    }
    // 1. Read s1 using getchar() loop
    printf("Enter the main string (s1): ");
    while ((c = getchar()) != '\n' && c != EOF && input_index < 999) {
        s1[input_index++] = (char)c;
    }
    s1[input_index] = '\0';
 
    // 2. Set bool array directly from s2 input
    printf("Enter characters to remove (s2): ");
    while ((c = getchar()) != '\n' && c != EOF)
{
    should_remove[(uint8_t)c] = true;
 
    if (c >= 'A' && c <= 'Z')
        should_remove[(uint8_t)(c + 32)] = true;
    else if (c >= 'a' && c <= 'z')
        should_remove[(uint8_t)(c - 32)] = true;
}
 
    output_index = 0;
    for (input_index = 0; s1[input_index] != '\0'; input_index++) {
        uint8_t current_char = (uint8_t)s1[input_index];
 
        if (!should_remove[current_char]) {
            s1[output_index] = s1[input_index];
            output_index++;
        }
    }
    s1[output_index] = '\0';
 
    // 4. Output result
    printf("Resulting string: %s\n", s1);
}
