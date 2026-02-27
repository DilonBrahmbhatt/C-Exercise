/*
program to print the corresponding Celsius to Fahrenheit table.
Author: Dilon Brahmbhatt
Created: 09 february, 2026
Modified: 09 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

void Celsius_to_Fahrenheit()
{
    uint16_t celsius;

    printf("Celsius:\n");
    scanf("%hu",&celsius);
    printf("F: %5.1f\n",(9.0/5.0)*celsius + 32);
}
