/*
Discribtion: Modify the pattern finding program of Chapter 5 to take its input from a set of named files or, if no files are named as arguments,
 	     from the standard input. Should the file name be printed when a matching line is found?
Author: Dilon Brahmbhatt
Created: 22 april, 2026
Modified: 22 april, 2026
*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define MAXLINE 1000

/* strstr-based pattern search: returns 1 if pattern found in line */
int match(char *line, char *pattern) {
    return strstr(line, pattern) != NULL;
}

/* search for pattern in a single FILE stream, label with name */
void search(FILE *fp, char *name, char *pattern) {
    char line[MAXLINE];
    int32_t lineno = 1;

    while (fgets(line, MAXLINE, fp) != NULL) {
        if (match(line, pattern))
            printf("%s:%d:%s", name, lineno, line);
        lineno++;
    }
}

void pattern_files_main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: find pattern [file...]\n");
        return 1;
    }

    char *pattern = argv[1];

    if (argc == 2) {
        /* no files given — read from stdin */
        search(stdin, "stdin", pattern);
    } else {
        /* search each named file */
        for (int i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "find: can't open %s\n", argv[i]);
                continue;
            }
            search(fp, argv[i], pattern);
            fclose(fp);
        }
    }
}
