/*
all common reuseble function are in this file.
Author: Dilon Brahmbhatt
Created: 06 february, 2026
Modified: 11 february, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include "header.h"

/*
switch program to call any DR.
Author: Dilon Brahmbhatt
Created: 06 february, 2026
Modified: 11 february, 2026
*/
void switch_choose_program() {
    uint8_t choice;
    bool c=true;
    while(c) {
        printf("\nDR:\n");
        c=false;
        scanf("%hhu", &choice);

        switch(choice) {
	case 1:
		DR_M1_switch();
		break;
	case 2:
		DR_M2_switch();
                break;
	case 3:
		DR_M3_switch();
		break;
	 case 4:
		DR_M4_switch();
		break;
	  default:
               printf("enter valid input");
	       break;
       }
    }
}


/*
description: this function is used for reversing the string.
Author: Dilon Brahmbhatt
Created: 27 february, 2026
Modified: 27 february, 2026
*/

void reverse_string(char str[])
{
    int8_t startIndex, endIndex;
    char tempChar;

    for (startIndex = 0, endIndex = strlen(str) - 1;
         startIndex < endIndex;
         startIndex++, endIndex--)
    {
        tempChar = str[startIndex];
        str[startIndex] = str[endIndex];
        str[endIndex] = tempChar;
    }
}

/* Stack storage */
static double stackValues[STACK_SIZE];
static int stackPointer = 0;

/* Input buffer */
static char inputBuffer[INPUT_BUFFER_SIZE];
static int bufferPosition = 0;

/*
description: this is the push function of the stack.
Author: Dilon Brahmbhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/

void push_to_stack(double value)

{
    if (stackPointer < STACK_SIZE)
        stackValues[stackPointer++] = value;
    else
        printf("stack full, cannot push %g\n", value);
}

/*
description: this is the pop function of the stack.
Author: Dilon Brahmhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/
double pop_from_stack()
{
    if (stackPointer > 0)
        return stackValues[--stackPointer];
    else {
        printf("stack empty\n");
        return 0.0;
    }
}

/*
description: this function takes the character using getchar and check buffer values available or not.
Author: Dilon Brahmbhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/
int16_t get_character()
{
    if (bufferPosition > 0)
        return inputBuffer[--bufferPosition];
    else
        return getchar();
}

/*
description: this is the pushback function used for extracting values from the buffer.
Author: Dilon Brahmbhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/
void pushback_character(int16_t ch)
{
    if (bufferPosition >= INPUT_BUFFER_SIZE)
        printf("pushback_character: too many characters\n");
    else
        inputBuffer[bufferPosition++] = ch;
}


/*
description: this function identifies the operator and return it.
Author: Dilon Brahmbhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/
int16_t get_token(char token[])
{
    int16_t index = 0;
    int16_t ch;
    /* Skip spaces and tabs */
    do {
        ch = get_character();
    } while (ch == ' ' || ch == '\t');
     token[0] = ch;
     token[1] = '\0';
     index = 0;
    if (islower(ch)) {
        while (islower(token[++index] = ch = get_character()));;
        token[index] = '\0';
        if (ch != EOF)
            pushback_character(ch);
        if (strlen(token) > 1)
            return NAME;
        else
            return token[0];
    }
    /* If not a number or decimal point or minus sign */
    if (!isdigit(ch) && ch != '.' && ch != '-') {
        return ch;
    }

    /* Handle negative number */
    if (ch == '-') {
        int16_t nextChar = get_character();

        if (!isdigit(nextChar) && nextChar != '.') {
            pushback_character(nextChar);
            return '-';
        }

        token[++index] = nextChar;
        ch = nextChar;
    }

    /* Collect integer part */
    while (isdigit(ch)) {
        ch = get_character();
        if (isdigit(ch)) {
            token[++index] = ch;
        }
    }

    if (ch == '.') {
        token[++index] = ch;

        while (isdigit(ch = get_character())) {
            token[++index] = ch;
        }
    }

    token[++index] = '\0';

    if (ch != EOF)
        pushback_character(ch);

    return NUMBER_TOKEN;
}

/*
description: this function clears the stack.
Author: Dilon Brahmbhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/

void clearsp() {
	stackPointer = 0;
}

/*
description: this function print the values from the stack.
Author: Dilon Brahmbhatt
Created: 03 march, 2026
Modified: 03 march, 2026
*/
void print_stack()
{
    int16_t i;
    for (i = 0; i < stackPointer; i++)
    {
        printf("%.0f ", stackValues[i]);
    }
    printf("\n");
}
