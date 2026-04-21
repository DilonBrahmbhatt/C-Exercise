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

void DR_M6_switch(int16_t argc, char *argv[]) {
    int8_t choice;
    bool c=true;
  while(c) {
        printf("\nfunction:\n");
        c=false;
        scanf("%hhu", &choice);

        switch(choice) {
                case 1: FrequecyOfKeywords();
                        break;
                case 2: BSTHandlingVariableCount(argc, argv);
                        break;
                case 3: LinePrintingWithWordCount();
                        break;
                case 4: SortDecendingOccurence();
                        break;
                case 5: InstallUndef();
                        break;
                case 6: DefinePreprocessorHandling();
                        break;
 		default:
                        break;
}
}
}
