#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "header.h"
/*
switch program to call any function from DR5.
Author: Dilon Brahmbhatt
Created: 30 march, 2026
Modified: 01 april, 2026
*/

void DR_M7_switch(int16_t argc, char *argv[]) {
    int8_t choice;
    bool c=true;
  while(c) {
        printf("\nfunction:\n");
        c=false;
        scanf("%hhu", &choice);

        switch(choice) {
                case 1:
			ArgLowerUpper(argc,argv);
                        break;
                case 2:
                        NongraphicHaxOctal();
                        break;
                case 3:
                        MinPrintfModified();
                        break;
                case 4:
                        RPNUsingScanf();
                        break;
                default:
                        break;
}
}
}

