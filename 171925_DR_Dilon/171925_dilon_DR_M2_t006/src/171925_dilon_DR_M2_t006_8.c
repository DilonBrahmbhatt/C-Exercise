/*
description: Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.
Author: Dilon Brahmbhatt
Created: 23 february, 2026
Modified: 23 february, 2026
*/
#include <stdio.h>
#include <stdint.h>
 
void rightrot()
{
    uint16_t Input;
    int16_t num_of_shifts;
    uint16_t left_part, right_part;
    const uint16_t BITS = 16;
 
    printf("Enter x (decimal): ");
    scanf("%hu", &Input);
 
    printf("Enter number of Shifts: ");
    scanf("%hd", &num_of_shifts);
 
    /* handle negative rotation */
    if (num_of_shifts < 0)
        num_of_shifts = BITS + num_of_shifts;
 
    num_of_shifts = num_of_shifts % BITS;
 
    right_part = Input >> num_of_shifts;
    left_part  = Input << (BITS - num_of_shifts);
 
    Input = right_part | left_part;
 
    printf("\nResult = %hu\n", Input);
}
