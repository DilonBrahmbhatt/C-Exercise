/*
description:In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.
Author: Dilon Brahmbhatt
Created: 23 february, 2026
Modified: 23 february, 2026
*/
#include <stdio.h>
#include <stdint.h>
 
void bitcount()
{
            int count = 0;
    unsigned Input;
 
    printf("Enter x (decimal): ");
    scanf("%u", &Input);
 
    while (Input != 0)
    {
        count++;
        Input &= (Input - 1);   // delete rightmost set bit
    }
 
    printf("Bit count: %d\n", count);
}
