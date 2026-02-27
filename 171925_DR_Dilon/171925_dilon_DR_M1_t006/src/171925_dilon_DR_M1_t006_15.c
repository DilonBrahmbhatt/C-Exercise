/*
Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.
Author: Dilon Brahmbhatt
Created: 11 february, 2026
Modified: 11 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

int16_t celsius_to_fahrenheit(int16_t c) {
    return (c * 9 / 5) + 32;
}

void c_to_f()
{
    int16_t celsius, fahr;

    printf("C: ");
    if (scanf("%hd", &celsius) == 1) {
        fahr = celsius_to_fahrenheit(celsius);
        printf("F:%hd\n",fahr);
    }
    else {
        printf("Please enter valid number\n");
    }

}
