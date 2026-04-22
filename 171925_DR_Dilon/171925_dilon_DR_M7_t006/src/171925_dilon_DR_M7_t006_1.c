/*
description: Write a program that converts upper case to lower or lower case to upper, depending on the name it is invoked with, as found in argv[0].
Author: Dilon Brahmbhatt
Created: 21 april, 2026
Modified: 21 april, 2026
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "header.h"

/*
description: This function takes argument from file name which is argv[0] and make decision accordingly.
Author: Ved Vyas
Created: 21 april, 2026
Modified: 21 april, 2026
*/
void ArgLowerUpper(int16_t argc, char *argv[]) {
    char line[MAXLINE];
    int16_t index;

    /* Validate argument */
    int to_upper = 0, to_lower = 0;

    if (strcmp(argv[0], "bin/upper") == 0)
        to_upper = 1;
    else if (strcmp(argv[0], "bin/lower") == 0)
        to_lower = 1;
    else {
        printf("Invalid option: %s\n", argv[0]);
        printf("Usage: %s [upper|lower]\n", argv[0]);
        return 1;
    }
clear_input_buffer();
printf("Enter you lines: \n");
    /* Read input and process */
    while (mgetline(line, MAXLINE) > 0) {
        for (index = 0; line[index] != '\0'; index++) {
            if (to_upper)
                putchar(toupper(line[index]));
            else
                putchar(tolower(line[index]));
        }
        putchar('\n');
    }
}
