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
#include "../inc/c3_YPK.h"

void C3_YPK_switch()
{
        int16_t choice;
    bool c = true;

    while(c) {
        printf("\n- YPK chapter 3 function list -\n");
        printf("Enter choice: ");
        c=false;
        scanf("%hu", &choice); //understand %hhu
        switch(choice) {
                case 1: find_first_occurence();
                        break;
                case 2: find_substring();
                        break;
                case 3: alpha_sort();
                        break;
                case 4: compressed_decompressed();
                        break;
                case 0: exit(0);
                default: printf("Invalid selection.\n");
}
}
}
