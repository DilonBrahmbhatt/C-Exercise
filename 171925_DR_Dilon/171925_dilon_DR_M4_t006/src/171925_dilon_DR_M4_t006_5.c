/*
discribtion: Add access to library functions like sin, exp, and pow.
Author: Dilon Brahmbhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "header.h"

/* math functions */
void mathfnc(char token[])
{
    double op2;

    if (strcmp(token, "sin") == 0)
    {
        double val = pop_from_stack();
        printf("sin(%.2f)\n", val);
        push_to_stack(sin(val));
    }
    else if (strcmp(token, "cos") == 0)
    {
        push_to_stack(cos(pop_from_stack()));
    }
    else if (strcmp(token, "exp") == 0)
    {
        double val = pop_from_stack();
        printf("e ^ %.2f\n", val);
        push_to_stack(exp(val));
    }
    else if (strcmp(token, "pow") == 0)
    {
        op2 = pop_from_stack();
        push_to_stack(pow(pop_from_stack(), op2));
    }
    else
    {
        printf("%s is not supported\n", token);
    }

    print_stack();
}

void add_sin_exp_pow()
{
    int16_t tokenType;
    double operand1, operand2;
    char token[MAX_TOKEN_LEN];

    /* clear leftover input */
    while ((tokenType = getchar()) != '\n' && tokenType != EOF);

    while ((tokenType = get_token(token)) != EOF)
    {
        switch (tokenType)
        {

        case NUMBER_TOKEN:
            push_to_stack(atof(token));
            break;

        case NAME:
            mathfnc(token);
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

        /* POWER operator for 2 ^ 3 */
        case '^':
            operand2 = pop_from_stack();
            operand1 = pop_from_stack();
            push_to_stack(pow(operand1, operand2));
            break;

        /* PRINT TOP */
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

        /* DUPLICATE */
        case 'd':
            printf("Stack before duplication: ");
            print_stack();

            operand2 = pop_from_stack();
            push_to_stack(operand2);
            push_to_stack(operand2);

            printf("Stack after duplication: ");
            print_stack();
            break;

        /* SWAP */
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
            printf("Ans = %.6f\n", pop_from_stack());
            break;

        default:
            printf("Unknown command %s\n", token);
            break;
        }
    }
}

