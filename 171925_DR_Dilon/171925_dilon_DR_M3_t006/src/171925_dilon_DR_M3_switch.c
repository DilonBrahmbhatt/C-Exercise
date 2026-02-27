#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "header.h"
/*
switch program to call any function from DR1.
Author: Dilon Brahmbhatt
Created: 24 february, 2026
Modified: 25 february, 2026
*/

void DR_M3_switch() {
    int8_t choice;
    bool c=true;
    while(c) {
        printf("\nfunction:\n");
        c=false;
        scanf("%hhu", &choice);

        switch(choice) {
                case 1:
			binary_search_main();
			break;
		case 2:
			replace_newline_tab();
			break;
		case 3:
			expand_main();
			break;
		case 4:
			input_and_convert();
			break;
		case 5:
			Digit_and_Base();
			break;
		case 6:
			Min_field_width();
			break;
		default:
			break;
}
}
}
