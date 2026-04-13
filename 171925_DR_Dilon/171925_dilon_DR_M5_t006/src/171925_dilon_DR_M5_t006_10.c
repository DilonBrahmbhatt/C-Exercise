/*
discribtion: Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.
Author: Dilon Brahmbhatt
Created: 06 april, 2026
Modified: 06 april, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "header.h"
void reverse_polish_calculator_with_argv()
{
    int16_t tokenType;
    double operand2;
    char token[MAX_TOKEN_LEN];
    while ((tokenType = get_token(token)) != EOF) {
 
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
