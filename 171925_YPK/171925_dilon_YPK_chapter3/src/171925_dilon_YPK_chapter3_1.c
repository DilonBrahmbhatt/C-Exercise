#include <stdio.h>
#include <string.h>
#include "../inc/c3_YPK.h"

// Custom strstr function to find substring
char *xstrstr(char *string1, char *string2) {
    if (*string2 == '\0') return string1; // Empty substring matches everything

    while (*string1 != '\0') {
        char *p1 = string1;
        char *p2 = string2;

        // Check if the substring matches starting at this position
        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (*p2 == '\0') {
            return string1; // Found the match!
        }
        string1++;
    }
    return NULL;
}

void find_first_occurence() {
    char str1[100];
    char str2[100];
    char *result;

    // Assuming clear_input_buffer is defined in your common_func.c
    // clear_input_buffer(); 

    printf("Enter the main string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove trailing newline

    printf("Enter the substring to find: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove trailing newline

    // Calling xstrstr (fixed name from xstrchr)
    result = xstrstr(str1, str2);

    if (result != NULL) {
        // Use str1 here instead of 'str'
        printf("Substring found at position: %ld\n", result - str1);
    } else {
        printf("Substring not found\n");
    }
}
