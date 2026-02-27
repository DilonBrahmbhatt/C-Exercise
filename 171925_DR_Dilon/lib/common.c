#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "header.h"

/*
all common reuseble function are in this file.
Author: Dilon Brahmbhatt
Created: 06 february, 2026
Modified: 11 february, 2026
*/


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

void reverse_string(char str[])
{
    int startIndex, endIndex;
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
