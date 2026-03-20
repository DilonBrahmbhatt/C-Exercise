/*a
discribtion: Add commands for handling variables.(It's easy to provide twenty-six variables with single-letter names.) Add a variable
             for the most recently printed value.
Author: Dilon Brahmbhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "header.h"

void handling_variables_RPN()
{
    int16_t tokenType, var;
    double operand2;
    char token[MAX_TOKEN_LEN];
double variable[26];
while (1)
    {
        tokenType = getchar();
        if (tokenType == '\n')
            break;
    }
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
        printf("zero divisor\n");

        break;
        }
        case '=':
            pop_from_stack();
            if (var >= 'A' && var <= 'Z')
                push_to_stack(variable[var - 'A'] = pop_from_stack());
            else
                printf("  no variable name\n");
            break;

         case '\n':
                printf("%.8g\n", pop_from_stack());
                break;

         default:
            if (tokenType >= 'A' && tokenType <= 'Z')
                push_to_stack(variable[tokenType - 'A']);
            else
                printf("unknown command %s\n", token);
            break;
        }
        var = tokenType;
        }
    }
