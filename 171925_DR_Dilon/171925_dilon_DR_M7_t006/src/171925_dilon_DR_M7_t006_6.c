/*
Discribtion: Write a program to compare two files, printing the first line where they differ.
Author: Dilon Brahmbhatt
Created: 22 april, 2026
Modified: 22 april, 2026
*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_LINE 1024

void main_file_comp(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
     return 0;
    }
    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");

    if (!f1 || !f2) {
        fprintf(stderr, "Error: could not open file(s)\n");
        return 1;
    }

    char line1[MAX_LINE], line2[MAX_LINE];
    uint32_t lineNum = 1;

while (1) {
        int r1 = fscanf(f1, "%1023[^\n]\n", line1);
        int r2 = fscanf(f2, "%1023[^\n]\n", line2);

        /* Both files ended — identical */
        if (r1 == EOF && r2 == EOF) {
            printf("Files are identical.\n");
            break;
        }
 
        /* One file ended before the other */
        if (r1 == EOF || r2 == EOF) {
            printf("Files have different lengths (differ at line %u).\n", lineNum);
            break;
        }
 
        /* Lines differ */
        if (strcmp(line1, line2) != 0) {
            printf("Files differ at line %u:\n", lineNum);
            printf("< %s", line1);
            printf("> %s", line2);
            break;
        }
 
        lineNum++;
    }
 
    fclose(f1);
    fclose(f2);
    return 0;
}

