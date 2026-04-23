/*
Discribtion: Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file.
Author: Dilon Brahmbhatt
Created: 23 april, 2026
Modified: 23 april, 2026
*/
#include <stdio.h>
#include <stdlib.h>

void printFile(const char *filename, int16_t pageLength) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
        exit(1);
    }

    printf("Title: %s\n\n", filename);

    char line[1024];
    int16_t lineCount = 0;
    int16_t pageCount = 1;

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
        lineCount++;

        if (lineCount == pageLength) {
            printf("\n--------------- Page %d ---------------\n", pageCount);
            printf("Press Enter to continue to the next page...");
            getchar();
            pageCount++;
            lineCount = 0;
        }
    }

    if (lineCount > 0) {
        printf("\n--------------- Page %d ---------------\n", pageCount);
    }

    fclose(fp);
    printf("\nEnd of File\n");
}

void main_file_page(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <page_length> <file1> [file2] ...\n", argv[0]);
        exit(1);
    }

    // Take page length from first argument
    int8_t pageLength = atoi(argv[1]);

    if (pageLength <= 0) {
        fprintf(stderr, "Error: Page length must be a positive number.\n");
        exit(1);
    }

    for (int8_t i = 2; i < argc; i++) {
        printFile(argv[i], pageLength);
        if (i < argc - 1) {
            printf("\n========== Starting next file ==========\n\n");
        }
    }
}
