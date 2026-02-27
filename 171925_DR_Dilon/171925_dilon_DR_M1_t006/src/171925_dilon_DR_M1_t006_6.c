/*
Verify that the expression getchar() != EOF is 0 or 1.
Author: Dilon Brahmbhatt
Created: 09 february, 2026
Modified: 09 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

void getchar_EOF_value()
{
uint8_t result;
    result = (getchar() != EOF);

    printf("%d\n", result);

}


