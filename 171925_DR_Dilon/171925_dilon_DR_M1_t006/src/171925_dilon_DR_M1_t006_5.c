/*
temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
Author: Dilon Brahmbhatt
Created: 09 february, 2026
Modified: 09 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

void Fahrenheit_to_Celsius_Table_Reverse()
{
    int16_t fahr;

    printf("Fahrenheit to Celsius Table (Reverse)\n");

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    {
        printf("%3d %5.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }

}
