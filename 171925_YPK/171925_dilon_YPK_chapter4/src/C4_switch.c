/*
description: this is the switching code which works for module two funtion selection.
Author: Dilon Brahmbhatt
Created: 18 march, 2026
Modified: 18 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "../inc/YPK.h"

void C4_YPK_switch()
{
        int16_t choice;
    bool c = true;

    while(c) {
        printf("\n- YPK chapter 4 function list -\n");
        printf("Enter choice: ");
        c=false;
        scanf("%hu", &choice);
        switch(choice) {
                case 1: determinantFind();
                        break;
		case 2: linkedList_operations();
			break;
                case 0: exit(0);
                default: printf("Invalid selection.\n");
}
}
}
