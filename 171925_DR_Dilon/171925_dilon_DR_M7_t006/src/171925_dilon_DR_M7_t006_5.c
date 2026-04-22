/*
Discribtion: Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the input and number conversion.
Author: Dilon Brahmbhatt
Created: 22 april, 2026
Modified: 22 april, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "header.h"
void RPNUsingScanf() {
    char buffer[MAXLINE];
    char token[50];
    char *ptr;
    int8_t offset;
clear_input_buffer();
    double num, op2;
    printf("Enter postfix expression: ");
    scanf("%[^\n]", buffer);
    ptr = buffer;
    while (*ptr != '\0') {
    while (*ptr == ' ' || *ptr == '\t')
        ptr++;
    if (isdigit(*ptr) || (*ptr == '-' && isdigit(*(ptr+1)))) {
        sscanf(ptr, "%lf%n", &num, &offset);
        push_to_stack(num);
        ptr += offset;
    }
    else {
        char op = *ptr;
        ptr++;
        switch (op) {
            case '+':
                push_to_stack(pop_from_stack() + pop_from_stack());
                break;
            case '*':
                push_to_stack(pop_from_stack() * pop_from_stack());
                break;
            case '-': {
                double op2 = pop_from_stack();
                push_to_stack(pop_from_stack() - op2);
                break;
            }
            case '/': {
                double op2 = pop_from_stack();
                if (op2 != 0.0)
                    push_to_stack(pop_from_stack() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            }
            case '%':
                {
                double operand2 = pop_from_stack();
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
            default:
                printf("error: unknown operator %c\n", op);
        }
    }
}
printf("Result: %.2f\n", pop_from_stack());
}
