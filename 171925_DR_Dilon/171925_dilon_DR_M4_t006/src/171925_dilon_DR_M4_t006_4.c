/*
discribtion: Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap
             the top two elements. Add a command to clear the stack.
Author: Dilon Brahmbhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "header.h"

void swap_duplicate_top()
{
    int16_t tokenType;
    double operand1, operand2;
    char token[MAX_TOKEN_LEN];

    while (1)
    {
        tokenType = getchar();
        if (tokenType == '\n')
            break;
    }

   while ((tokenType = get_token(token)) != EOF)
    {

        switch (tokenType)
        {

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
            operand1 = pop_from_stack();

            if (operand2 != 0.0)
            {
                double result = fmod(fmod(operand1, operand2) + operand2, operand2);
                push_to_stack(result);
            }
            else
                printf("zero divisor\n");

            break;
        }

        /* PRINT TOP WITHOUT REMOVING */
        case '?':

            operand2 = pop_from_stack();
            printf("\t%.8g\n", operand2);
            push_to_stack(operand2);
            break;

        /* CLEAR STACK */
        case 'c':

            printf("Clear the Stack\n");
            clearsp();
            break;

        /* DUPLICATE TOP */
        case 'd':

            printf("Stack before duplication: ");
            print_stack();

            operand2 = pop_from_stack();
            push_to_stack(operand2);
            push_to_stack(operand2);

            printf("Stack after duplication: ");
            print_stack();

            break;

        /* SWAP TOP TWO */
        case 's':

            printf("Stack before swapping: ");
            print_stack();

            operand1 = pop_from_stack();
            operand2 = pop_from_stack();

            push_to_stack(operand1);
            push_to_stack(operand2);

            printf("Stack after swapping: ");
            print_stack();

            break;

        case '\n':

            printf("\t%.8g\n", pop_from_stack());
            break;

        default:

            printf("Unknown command %s\n", token);
            break;
        }
    }
}


