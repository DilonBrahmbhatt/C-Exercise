/*
discribtion:An alternate organization uses getline to read an entire input line; this makes getch and ungetch unnecessary. Revise the calculator to use this approach.
Author: Dilon Brahmbhatt
Created: 09 march, 2026
Modified: 09 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>
#include "header.h"
int16_t getop_revised(char s[]);
void RPN_using_getline_function()
{
    int16_t tokenType;
    double operand2;
    char token[MAX_TOKEN_LEN];
while (1)
    {
       int16_t tokenType = getchar();
        if (tokenType == '\n')
            break;
    }
    while ((tokenType = getop_revised(token)) != EOF) {

        switch (tokenType) {

        case NUMBER_TOKEN:
            push_to_stack(atof(token));
            break;

        case '+':
            push_to_stack(pop_from_stack() + pop_from_stack());
            break;

        case '*':
            push_to_stack(pop_from_stack() * pop_from_stack());
            break;

        case '-':
            operand2 = pop_from_stack();
            push_to_stack(pop_from_stack() - operand2);
            break;

        case '/':
            operand2 = pop_from_stack();

            if (operand2 != 0.0)
                push_to_stack(pop_from_stack() / operand2);
            else
                printf("zero divisor\n");

            break;

        case '%':
        {
        operand2 = pop_from_stack();
        double operand1 = pop_from_stack();

    if (operand2 != 0.0)
        {
        double result = fmod(fmod(operand1, operand2) + operand2, operand2);
        push_to_stack(result);
        }
         else
        printf(" zero divisor\n");

        break;
        }
         case '\n':
                printf("\t%.8g\n", pop_from_stack());
                break;

        default:
            printf("unknown command %s\n", token);
            break;
        }
    }
}

int16_t line_index = 0;
char line[MAXLINE];
int16_t getop_revised(char s[])
{
    int16_t c;
    int16_t i;

    if (line[line_index] == '\0')
    {
        if (mgetline(line, MAXLINE) == 0)
        {
            return EOF;
        }
        else
        {
            line_index = 0;
        }
    }

    /* skip spaces */
    do
    {
        c = line[line_index++];
    }
    while (c == ' ' || c == '\t');

    s[0] = c;
    s[1] = '\0';

    /* handle minus sign */
    if (c == '-')
    {
        char next = line[line_index];

        /* if next char is not digit or '.' then it is subtraction operator */
        if (!isdigit(next) && next != '.')
        {
            return c;
        }
    }

    /* if not digit, '.', or '-' → operator */
    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    i = 0;

    /* store '-' if negative number */
    if (c == '-')
    {
        s[i++] = c;
        c = line[line_index++];
    }

    /* integer part */
    if (isdigit(c))
    {
        do
        {
            s[i++] = c;
            c = line[line_index++];
        }
        while (isdigit(c));
    }

    /* fractional part */
    if (c == '.')
    {
        do
        {
            s[i++] = c;
            c = line[line_index++];
        }
        while (isdigit(c));
    }

    s[i] = '\0';

    /* step back one char */
    if (line_index > 0)
    {
        line_index--;
    }

    return NUMBER_TOKEN;
}
