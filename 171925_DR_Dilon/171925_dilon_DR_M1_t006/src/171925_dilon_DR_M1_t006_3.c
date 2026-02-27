/*
the temperature conversion program to print a heading above the table.
Author: Dilon Brahmbhatt
Created: 09 february, 2026
Modified: 09 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

void print_table_Fahrenheit_to_Celsius()
{
    uint16_t fahr;

    printf("Fahrenheit to Celsius Table\n");

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    {
        printf("%3d %5.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }

}
