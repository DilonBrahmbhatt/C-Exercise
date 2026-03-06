/*
this will contain defination of all the function.
Author: Dilon Brahmbhatt
Created: 06 february, 2026
Modified: 06 march, 2026
*/

#ifndef HEADER_H
#define HEADER_H

/* stack related function declaration */
#define MAX_TOKEN_LEN 100
#define NUMBER_TOKEN '0'
#define NAME 'n'
#define INPUT_BUFFER_SIZE 100
#define STACK_SIZE 100

/*main switch function for getting module*/
void switch_choose_program();

/*each module switch function*/
void DR_M1_switch();
void DR_M2_switch();
void DR_M3_switch();
void DR_M4_switch();

/*common function*/
void reverse_string(char str[]);
void push_to_stack(double value);
double pop_from_stack();
int16_t get_character();
void pushback_character(int16_t ch);
int16_t get_token(char token[]);
void clearsp();
void print_stack();

/*all module1 function definarion*/
void hellow_world();
void hello_world_with_slash_c();
void getchar_EOF_value();
void value_of_EOF();
void c_to_f();
void Celsius_to_Fahrenheit();
void print_table_Fahrenheit_to_Celsius();
void Fahrenheit_to_Celsius_Table_Reverse();
void count_blanks_tabs_newlines();
void runWordCountTest();
void display_words_linewise();
void word_length_histogram();
void plot_word_length_histogram();
void replacing_each_string_of_one_or_more_blanks_by_single_blank();
void print_visible_control_chars();
void find_longest_line();
void print_lines_longer_than_8();
void remove_trailing_blanks_tabs();
void detab_input_stream();
void entab_input_text_stream();
void fold_line();

/*all module2 function definarion*/
void size_of_data_type();
void get_input_no_logic_ops();
void htoi();
void squeeze();
void any();
void setbits_1();
void invert();
void rightrot();
void bitcount();
void Uper_to_Lower();

/*all module3 function definarion*/
void binary_search_main();
void replace_newline_tab();
void expand_main();
void input_and_convert();
void Digit_and_Base();
void Min_field_width();

/*all module4 function definarion*/
void strindex_main();
void atof_main();
void reverse_polish_calculator();
void swap_duplicate_top();
void add_sin_exp_pow();
void handling_variables_RPN();

#endif /* HEADER_H */

