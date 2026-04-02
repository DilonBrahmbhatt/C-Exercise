/*
description: Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
Author : Dilon Brahmbhatt
Created: 09 march, 2026
Modified: 09 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>
#include "header.h"
int16_t getop_revised_q11(char s[]);
void RPN_using_static_var_function()
{
    int16_t tokenType;
    double operand2;
    char token[MAX_TOKEN_LEN];
while (1)
    {
        tokenType = getchar();
        if (tokenType == '\n')
            break;
    }
    while ((tokenType = getop_revised_q11(token)) != EOF) {

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


int16_t getop_revised_q11(char s[])
{
    int16_t i = 0;
    static int16_t prev_character = 0;
    int16_t c;
char next_character;
    if (prev_character != 0)
    {
        c = prev_character;
        prev_character = 0;
    }
    else
    {
        c = getchar();
    }

    while (c == ' ' || c == '\t')
        c = getchar();

    s[0] = c;
    s[1] = '\0';
if (c == '-')
    {
         next_character = getchar();

       if (!isdigit(next_character) && next_character != '.')
        {
            return c;
        }
    }


    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    i = 0;

    if (c == '-')
    {
        s[i++] = c;
        c = next_character;
    }

    if (isdigit(c))
    {
        do
        {
            s[i++] = c;
            c = getchar();
        } while (isdigit(c));
    }

   if (c == '.')
    {
        do
        {
            s[i++] = c;
            c = getchar();
        } while (isdigit(c));
    }

    s[i] = '\0';

    prev_character = c;

    return NUMBER_TOKEN;
}
