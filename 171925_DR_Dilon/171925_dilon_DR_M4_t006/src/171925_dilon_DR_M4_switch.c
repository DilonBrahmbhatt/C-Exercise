#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "header.h"
/*
switch program to call any function from DR4.
Author: Dilon Brahmbhatt
Created: 27 february, 2026
Modified: 27 february, 2026
*/
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
	default:
		break;
	}
}
}
