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
void DR_M1_switch() {
    uint8_t choice;
    bool c=true;
    while(c) {
        printf("\nfunction:\n");
        c=false;
        scanf("%hhu", &choice);

        switch(choice) {
          case 1:
                hellow_world();
                break;
          case 2:
                hello_world_with_slash_c();
                break;
          case 3:
                print_table_Fahrenheit_to_Celsius();
                break;
          case 4:
                Celsius_to_Fahrenheit();
                break;
          case 5:
                Fahrenheit_to_Celsius_Table_Reverse();
                break;
          case 6:
                getchar_EOF_value();
                break;
          case 7:
                value_of_EOF();
                break;
          case 8:
                count_blanks_tabs_newlines();
                break;
          case 9:
                replacing_each_string_of_one_or_more_blanks_by_single_blank();
                break;
          case 10:
                print_visible_control_chars();
                break;
          case 11:
                runWordCountTest();
                break;
          case 12:
                display_words_linewise();
                break;
          case 13:
                word_length_histogram();
                break;
          case 14:
                plot_word_length_histogram();
                break;
          case 15:
                c_to_f();
                break;
          case 16:
                find_longest_line();
                break;
          case 17:
                print_lines_longer_than_8();
                break;
          case 18:
                remove_trailing_blanks_tabs();
                break;
          case 19:
                reverse_line();
                break;
          case 20:
                detab_input_stream();
                break;
          case 21:
                entab_input_text_stream();
                break;
          case 22:
                fold_line();
                break;
	  case 23:
		remove_comments();
		break;
	  case 24:
		check_c_syntax();
		break;
          case 0:
                exit(0);
          default:
                printf("Invalid selection.\n");
        }
    }
}
