#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "header.h"
/*
switch program to call any function from DR1.
Author: Dilon Brahmbhatt
Created: 06 february, 2026
Modified: 11 february, 2026
*/

void DR_M2_switch() {
    int8_t choice;
    bool c=true;
    while(c) {
        printf("\nfunction:\n");
        c=false;
        scanf("%hhu", &choice);

	switch(choice) {
		case 1: size_of_data_type();
                        break;
                case 2: get_input_no_logic_ops();
                        break;
                case 3: htoi();
                        break;
                case 4: squeeze();
                        break;
                case 5: any();
                        break;
                case 6: setbits();
			break;
		case 7: invert();
                        break;
                case 8: rightrot();
                        break;
                case 9: bitcount();
                        break;
                case 10: Uper_to_Lower();
                        break;
                case 0: exit(0);
                default: printf("Invalid selection.\n");
		break;
}
}
}
