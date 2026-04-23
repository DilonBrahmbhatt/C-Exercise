/*
Description: Implement a simple version of the #define processor (i.e., no arguments)
         suitable for use with C programs, based on the routines of this section.
        You may also find getch and ungetch helpful.
Author: Dilon Brahmbhatt
Created: 20 April, 2026
Modified: 20 April, 2026
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define IN 1
#define OUT 0

int mgetword(char *word, int lim, int *lineno_addr) {
    int c, d;
    char *w = word;

    /* Skip whitespace */
    while ((c = get_character()) != EOF && isspace(c)) {
        if (c == '\n')
            (*lineno_addr)++;
    }

    /* Handle EOF */
    if (c == EOF)
        return EOF;

    /* Handle comments */
    if (c == '/') {
        if ((d = get_character()) == '*') {
            /* inside comment */
            while ((c = get_character()) != EOF) {
                if (c == '\n')
                    (*lineno_addr)++;

                if (c == '*') {
                    if ((c = get_character()) == '/')
                        break;
                    else
                        pushback_character(c);
                }
            }
            return mgetword(word, lim, lineno_addr); // continue after comment
        } else {
            pushback_character(d);
        }
    }

    /* Handle string literals */
    if (c == '"') {
        *w++ = c;
        while ((c = get_character()) != EOF) {
            *w++ = c;
            if (c == '"')
                break;
            if (c == '\\')  // escaped character
                *w++ = get_character();
        }
        *w = '\0';
        return word[0];
    }
 
    /* Handle preprocessor directive (#define etc.) */
    if (c == '#') {
        *w++ = c;
        while ((c = get_character()) != EOF && !isspace(c)) {
            *w++ = c;
        }
        *w = '\0';
        return word[0];
    }

    /* Normal word (identifier) */
    if (isalnum(c) || c == '_') {
        *w++ = c;
        while (--lim > 0) {
            c = get_character();
            if (c == EOF)
                break;
            if (!isalnum(c) && c != '_') {
                pushback_character(c);
                break;
            }
            *w++ = c;
        }
        *w = '\0';
        return word[0];
    }
 
    /* Single character */
    *w++ = c;
    *w = '\0';
 
    return c;
}
int is_valid_identifier(char *s) {
    if (!isalpha(s[0]) && s[0] != '_')
        return 0;

    for (int i = 1; s[i] != '\0'; i++) {
        if (!isalnum(s[i]) && s[i] != '_')
            return 0;
    }
    return 1;
}

void DefinePreprocessorHandling() {
    int lineno = 1;
    char word[MAXWORD];
    char key[MAXWORD], value[MAXWORD];
    struct nlist *result;
clear_input_buffer();
    while (mgetword(word, MAXWORD, &lineno) != EOF) {

    if (word[0] == '#') {

        if (strcmp(word, "#define") == 0) {

            if (mgetword(key, MAXWORD, &lineno) == EOF) {
                printf("Error at line %d: Missing identifier after #define\n", lineno);
                continue;
            }

            if (!is_valid_identifier(key)) {
                printf("Error at line %d: Invalid identifier '%s'\n", lineno, key);
                continue;
            }

            if (mgetword(value, MAXWORD, &lineno) == EOF) {
                printf("Error at line %d: Missing value for '%s'\n", lineno, key);
                continue;
            }

            install(key, value);

            struct nlist *result = lookup(key);
            printf("%s -> %s\n", result->name, result->defn);

        } else {
             printf("Error at line %d: Invalid preprocessor directive '%s'\n", lineno, word);
        }
    }
}
}
