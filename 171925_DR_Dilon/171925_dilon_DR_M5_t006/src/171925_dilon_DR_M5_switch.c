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

void DR_M5_switch(int16_t argc, char *argv[]) {
    int8_t choice;
    bool c=true;
  while(c) {
        printf("\nfunction:\n");
        c=false;
        scanf("%hhu", &choice);

        switch(choice) {
                case 1:
			validNumberRPN();
			break;
		case 2:
			validFloatRPN();
			break;
		case 3:
			strcatMain();
			break;
		case 4:
			strend_main();
			break;
                case 5:
                        cpy_Cmp_Cat();
                        break;
                case 6:
                        strend_main();
                        break;
                case 7:
                        ReadWriteLines();
                        break;
                case 8:
                        main_day_of_year();
                        break;
                case 9:
                        main_day_of_year_using_pointer();
                        break;
		case 10:{
                        process_args(argc, argv);
                        reverse_polish_calculator_with_argv();
                        break;}
		case 11:{
                        process_args(argc, argv);
                        HandleEntabDetabArgs(argc,argv);
                        break;}
                case 12:{
                        process_args(argc, argv);
                        ShortHandDetabEntab(argc,argv);
                        break;}
                case 13:{
                        process_args(argc, argv);
                        ReadLineTail(argc,argv);
                        break;}
		default:
                        break;
}
}
}

