/*
Discribtion: Make dcl recover from input errors.
Author: Dilon Brahmbhatt
Created: 13 april, 2026
Modified: 13 april, 2026
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"
/* function prototypes */
int gettoken(void);
void dcl(void);
void dirdcl(void);
void DeclarationToWords()
{
        clear_input_buffer();
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        name[0] = '\0';
        error = 0;
        dcl();
        if (tokentype != '\n' && tokentype != EOF)
            printf("syntax error\n");
        if (!error && tokentype == '\n' && name[0] != '\0')
    printf("%s: %s %s\n", name, out, datatype);
        /* skip rest of line (error recovery) */
        while (tokentype != '\n' && tokentype != EOF)
            tokentype = gettoken();
    }
}
/* dcl: parse a declarator */
void dcl(void)
{
    int ns = 0;
    while (gettoken() == '*')
        ns++;
dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void)
{
    int type;
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
            error = 1;
        }
    }
    else if (tokentype == NAMES) {
        strcpy(name, token);
    }
    else {
        printf("error: expected name or (dcl)\n");
        error = 1;
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
if (tokentype != '\n' && tokentype != ')' &&
    tokentype != PARENS && tokentype != BRACKETS && tokentype != EOF) {

    printf("error: expected name or (dcl)\n");
    error = 1;
}
}

/* gettoken: return next token */
int gettoken(void)
{
    int c;
    char *p = token;
    /* skip whitespace */
    while ((c = get_character()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            pushback_character(c);
            return tokentype = '(';
        }
    }
    else if (c == '[') {
        *p++ = c;
        while ((*p++ = get_character()) != ']')
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c)) {
        *p++ = c;
        while (isalnum(c = get_character()))
            *p++ = c;
        *p = '\0';
        pushback_character(c);
        return tokentype = NAMES;
    }
    else {
        return tokentype = c;
    }
}
