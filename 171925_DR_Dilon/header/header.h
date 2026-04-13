/*
this will contain defination of all the function.
Author: Dilon Brahmbhatt
Created: 06 february, 2026
Modified: 01 april, 2026
*/

#ifndef HEADER_H
#define HEADER_H
#include <stdint.h>
#include <stdbool.h>

/* stack related function declaration */
#define MAX_TOKEN_LEN 100
#define NUMBER_TOKEN '0'
#define NAME 'n'
#define INPUT_BUFFER_SIZE 100
#define STACK_SIZE 100
#define MAXLINE 1000

/* Stack functions */
void push_to_stack(double value);
double pop_from_stack(void);

/* Input buffer functions */
int16_t get_character(void);
void pushback_character(int16_t ch);

/* Token reader */
int16_t get_token(char token[]);
void clearsp();
void print_stack();

/* getline and ungets function declaration */
void ungets(char s[]);
int16_t mgetline(char line[], int16_t maxline);

/* updated getch and ungetch functions for quesion 9 */
int16_t getch();
void ungetch(int16_t c);
int16_t getop(char token[]);

/*main switch function for getting module*/
void switch_choose_program(int16_t argc, char *argv[]);

/*each module switch function*/
void DR_M1_switch();
void DR_M2_switch();
void DR_M3_switch();
void DR_M4_switch();
void DR_M5_switch(int16_t argc, char *argv[]);

/*common function*/
void reverse_string(char str[]);
void push_to_stack(double value);
double pop_from_stack();
int16_t get_character();
void pushback_character(int16_t ch);
int16_t get_token(char token[]);
void clearsp();
void print_stack();
int16_t mgetline(char s[], int16_t lim);
void ungets(char s[]);
int16_t getch();
void ungetch(int16_t c);
int16_t getop(char token[]);
void clear_input_buffer();
void process_args(int16_t argc, char *argv[]);

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
void reverse_line();
void detab_input_stream(int16_t TABSIZE);
void entab_input_text_stream();
void fold_line();

/*all module2 function definarion*/
void size_of_data_type();
void get_input_no_logic_ops();
void htoi();
void squeeze();
void any();
void setbits();
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
void ungets_main();
void updated_getch_ungetch();
void EOF_handling();
void RPN_using_getline_function();
void RPN_using_static_var_function();
void itoa_using_recursion();
void swap_duplicate_top();
void macro_swap();

/*all module5 function definarion*/
void validNumberRPN();
void validFloatRPN();
void strcatMain();
void strend_main();
void ReadWriteLines();
void reverse_polish_calculator_with_argv();
void HandleEntabDetabArgs(int16_t argc, char *argv[]);
void ShortHandDetabEntab(int16_t argc, char *argv[]);
void ReverseSorting(int16_t argc, char *argv[]);
void FoldingAlphabets(int16_t argc, char *argv[]);
#endif /* HEADER_H */

