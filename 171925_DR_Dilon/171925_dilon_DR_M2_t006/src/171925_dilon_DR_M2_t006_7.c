/*
description: Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
Author: Dilon Brhmbhatt
Created: 23 february, 2026
Modified: 23 february, 2026
*/
#include <stdio.h>
#include <stdint.h>
 
void invert()
{
    unsigned Input_first, Input_second;
    int16_t position, num_of_bit;
    unsigned ybits;
    unsigned mask;
    unsigned shift;
 
    printf("Enter x (decimal): ");
    scanf("%d", &Input_first);
 
    printf("Enter position p: ");
    scanf("%hd", &position);
 
    printf("Enter number of bits n: ");
    scanf("%hd", &num_of_bit);
 
    if (Input_first < 0 || Input_second < 0 || position < 0 || num_of_bit < 0)   // Validation: positive values check
    {
        printf("Enter positive value\n");
        return;
    }
 
    if (num_of_bit > position + 1)  // Validation: bit range check
    {
        printf("Insufficient bits. N should be >= P + 1\n");
        return;
    }
 
    shift = position + 1 - num_of_bit;
 
    mask = ~(~0U << num_of_bit);
    mask = mask << shift;
 
    Input_first = Input_first ^ mask;
    printf("\nResult = %d\n", Input_first);
}
