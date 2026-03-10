/*
description:Write a loop equivalent to the for loop above without using && or ||.
Author: Dilon Brahmbhatt
Created: 20 february, 2026
Modified: 20 february, 2026
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 1000

void get_input_no_logic_ops() {
    char s[MAX_LIMIT];
    int16_t index, ch;
    int8_t loop_active = 1;

    printf("Enter your text (Press Enter or Ctrl+D to finish):\n");
    if(getchar()=='\n')
	{;}

    for (index = 0; loop_active == 1; index++) {
        if (index >= MAX_LIMIT - 1) {
            loop_active = 0;
        } else {
            ch = getchar();
            if (ch == EOF) {
                loop_active = 0;
            }
            else if (ch == '\n') {
                loop_active = 0;
            }
            else {
                s[index] = ch;
            }
        }
    }

    s[index-1] = '\0';

    printf("%s\n", s);
}
