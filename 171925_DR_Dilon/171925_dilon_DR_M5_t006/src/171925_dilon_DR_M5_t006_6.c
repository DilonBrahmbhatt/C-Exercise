/*
description:Write versions of the library functions strncpy, strncat, and strncmp,
                 which operate on at most the first n characters of their argument
                strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
                Full descriptions are in Appendix B.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 01-04-2026
*/
#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

/*

description: this is getline function implemented with pointer.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 01-04-2026
*/

int getline_ptr(char *s, int lim)

{

    int c;

    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')

        *s++ = c;

    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}

/*
description: this is reverse string function implemented with pointer.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 01-04-2026
*/
void reverse_stringPtr(char *str)
{
    char *end = str + strlen(str) - 1;
    char temp;
    while (str < end)
    {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}
/*
description: this is integer to ascii function implemented with pointer.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 01-04-2026
*/
void itoa_ptr(int number, char *resultStr)
{
    int sign = number;
    char *start = resultStr;
    if (number < 0)
        number = -(number + 1);
    do
    {
        *resultStr++ = (number % 10) + '0';
    } while ((number /= 10) > 0);
    if (sign < 0)
        *resultStr++ = '-';
    *resultStr = '\0';
    reverse_stringPtr(start);
    if (sign < 0)
        *(start + strlen(start) - 1) += 1;
}
/*
description: this is ascii to integer function implemented with pointer.
author: Dilon Brhmbhatt
created date: 31-03-2026
modified date: 31-03-2026
*/
int atoi_ptr(char *s)
{
    int sign = 1;
    int result = 0;
    while (isspace(*s))
        s++;
    if (*s == '-' || *s == '+')
        sign = (*s++ == '-') ? -1 : 1;
    while (isdigit(*s))

    {

        result = result * 10 + (*s - '0');

        s++;

    }
    return sign * result;
}

/*
description: this is get operation funtion of RPN calculator implemented with pointer.
author: Dilon Brhmbhatt
created date: 30-03-2026
modified date: 01-04-2026
*/

int getTokenPtr(char *token)
{
    int ch;
    char *t = token;
    while ((ch = get_character()) == ' ' || ch == '\t');

    *t++ = ch;

    *t = '\0';

    if (islower(ch))

    {

        while (islower(*t++ = ch = get_character()));

        *(t - 1) = '\0';

        if (ch != EOF)

            pushback_character(ch);

       return NAME;

    }

    if (!isdigit(ch) && ch != '.' && ch != '-')

        return ch;

    if (ch == '-')

    {

        int next = get_character();

        if (!isdigit(next) && next != '.')

        {

            pushback_character(next);

            return '-';

        }

        *t++ = next;

        ch = next;

    }
 
    while (isdigit(ch))

    {

        ch = get_character();

        if (isdigit(ch))

            *t++ = ch;

    }
    if (ch == '.')
    {
        *t++ = ch;
        while (isdigit(ch = get_character()))
            *t++ = ch;
    }
    *t = '\0';
    if (ch != EOF)
        pushback_character(ch);
    return NUMBER_TOKEN;
}

int strindex_ptr(char *mainStr, char *searchStr)
{
    char *p1, *p2, *start;
    char *lastMatch = NULL;
    for (start = mainStr; *start != '\0'; start++)
    {
        p1 = start;
        p2 = searchStr;
        while (*p2 != '\0' && *p1 == *p2)
        {
            p1++;
            p2++;
        }
        if (*p2 == '\0')
        {
            lastMatch = start;
        }
    }
    if (lastMatch != NULL)
        return lastMatch - mainStr + 1;
    return -1;
}

void pointerBasedFunctions()

{

    int choice;
    char str[MAXLINE], result[MAXLINE];
    int num;
    while (1)
    {
        printf("\n--- POINTER BASED FUNCTIONS ---\n");
        printf("1. getline\n");
        printf("2. itoa\n");
        printf("3. atoi\n");
        printf("4. reverse string\n");
        printf("5. get_token\n");
        printf("6. strindex\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline
        switch (choice)
        {
        case 1:
            printf("Enter a line:\n");
            getline_ptr(str, MAXLINE);
            printf("You entered: %s", str);
            break;
        case 2:
            printf("Enter number: ");
            scanf("%d", &num);
            itoa_ptr(num, result);
            printf("String: %s\n", result);
            break;
        case 3:
            printf("Enter string number: ");
            scanf("%s", str);
            printf("Integer: %d\n", atoi_ptr(str));
            break;
        case 4:
            printf("Enter string: ");
            scanf("%s", str);
            reverse_stringPtr(str);
            printf("Reversed: %s\n", str);
            break;
        case 5:
        {
                int16_t tokenType;
                double operand2;
                char token[MAX_TOKEN_LEN];
                while ((tokenType = getTokenPtr(token)) != EOF) {
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
        case 6:
        {
            char mainStr[MAXLINE], searchStr[MAXLINE];
            printf("Enter main string: ");
                mgetline(mainStr,MAXLINE);
            printf("Enter search string: ");
              mgetline(searchStr,MAXLINE);
            int index = strindex_ptr(mainStr, searchStr);
            if (index >= 0)

                printf("Found at index: %d\n", index);

            else

                printf("Not found\n");

            break;

        }

        case 0:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

