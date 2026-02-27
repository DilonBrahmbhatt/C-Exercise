/*
description:Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
Author: Dilon Brhmbhatt
Created: 23 february, 2026
Modified: 23 february, 2026
version: 2
*/
#include <stdio.h>
#include <stdint.h>
 
void setbits()
{
    unsigned Input_first, Input_second;
    int16_t position, num_of_bit;
    unsigned ybits;
    unsigned mask;
    unsigned shift;
 
    printf("Enter x (decimal): ");
    scanf("%d", &Input_first);
 
    printf("Enter y (decimal): ");
    scanf("%d", &Input_second);
 
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
    ybits = Input_second & mask;
    ybits = ybits << shift;
 
    mask = mask << shift;
 
    Input_first = Input_first & ~mask;
    Input_first = Input_first | ybits;
 
    printf("\nResult = %d\n", Input_first);
}
