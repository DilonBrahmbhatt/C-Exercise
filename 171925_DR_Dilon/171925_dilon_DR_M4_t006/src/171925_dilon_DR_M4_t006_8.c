/*
description: Write a routine ungets(s) that will push back an entire string onto the input.
                 Should ungets know about buf and bufp, or should it just use ungetch?
Author :Dilon Brahmbhatt
Created: 06 march, 2026
Modified: 06 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "header.h"
#define MAXLINE 100

void updated_getch_ungetch()
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
    while ((tokenType = getop(token)) != EOF) {

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
