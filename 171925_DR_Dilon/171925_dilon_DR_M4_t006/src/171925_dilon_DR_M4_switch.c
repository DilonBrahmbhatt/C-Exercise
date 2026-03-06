/*
switch program to call any function from DR4.
Author: Dilon Brahmbhatt
Created: 27 february, 2026
Modified: 06 march, 2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "header.h"

void DR_M4_switch() {
    uint8_t choice;
    bool c=true;
    while(c) {
        printf("\nfunction:\n");
        c=false;
        scanf("%hhu", &choice);

	switch(choice) {
	case 1:
                strindex_main();
                break;
	case 2:
		atof_main();
		break;
        case 3:
               reverse_polish_calculator();
                break;
        case 4:
               swap_duplicate_top();
                break;
        case 5:
                add_sin_exp_pow();
                break;
        case 6:
               handling_variables_RPN();
                break;
	default:
		break;
	}
}
}
