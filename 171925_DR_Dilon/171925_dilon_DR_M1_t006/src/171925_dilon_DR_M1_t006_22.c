/*
Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs
before the n-th column of input.Make sure your program does something intelligent with very long lines, and if there are no blanks
or tabs before the specified column.
Author: Dilon Brahmbhatt
Created: 13 february, 2026
Modified: 13 february, 2026
*/
#include <stdio.h>
#include <stdint.h>
#define MAX 100
void fold_line()
{
int8_t last_space=-1;
int8_t fold=10;
int8_t index=0;
int16_t ch;
int8_t last_new_line=0;
char char_arr[MAX];
	while ((ch = getchar()) != EOF)
	 {
		if(ch == ' ' || ch == '\t')
		 {
			last_space=index;
		 }
		char_arr[index]=(char)ch;
		if(last_new_line+fold<=index && last_space!=-1)
		 {
			char_arr[last_space]='\n';
			last_new_line=last_space+1;
			last_space=-1;
		 }
		index++;
	 }
char_arr[index] = '\0';
printf("\n%s", char_arr);
}
