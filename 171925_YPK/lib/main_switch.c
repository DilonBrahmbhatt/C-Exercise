/*
description: this is the switching code which work for module selection.
Author: Dilon Brahmbhatt
Created: 07 february, 2026
Modified: 03 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "../inc/YPK.h"
void switch_choose_module()
{
    uint8_t choice;
    bool c = true;

    while(c) {
        printf("\n==== MASTER MENU ====\n");
        printf("1. YPK chapter 3\n");
        printf("2. YPK chapter 4\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%hhu", &choice);
        c = false;
        switch(choice) {
            case 1:
                C3_YPK_switch();
                break;
            case 2:
                C4_YPK_switch();
                break;
            case 0:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}
