/*
Description: Write a program that will print arbitrary input in a sensible way. As a minimum,
         it should print non-graphic characters in octal or hexadecimal according to local custom and break long text lines.
Author: DIlon Brahmbhatt
Created: 21 april, 2026
Modified: 21 april, 2026
*/
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include "header.h"
#define HEXLEN 4
#define MAXLINELENGTH 50
/*
Description: This function increament the position as character occurs
        and if length of line is larger than wanted than it will break the line.
Author: ved vyas
Created: 21 april, 2026
Modified: 21 april, 2026
*/
int16_t inc(int16_t pos, int16_t num) {
    if (pos + num >= MAXLINELENGTH) {
        putchar('\n');
        return num;
    } else {
        return pos + num;
    }
}

/*
Description: This function use isprint() to identify graphical character and avoid nongraphical characters.
                on behalf on nongraphical it prints hex and otal values.
Author: Dilon Brahmbhatt
Created: 21 april, 2026
Modified: 21 april, 2026
*/
void NongraphicHaxOctal() {
    char line[MAXLINE];
    int16_t pos, index, character;
    while (1) {
        clear_input_buffer();
        printf("Enter text (press Enter to print, or Ctrl+D to exit):\n");
if (mgetline(line, MAXLINE) == 0)
            break;

        printf("Output:\n");
        pos = 0;
        for (index = 0; line[index] != '\0'; index++) {
            character = line[index];
            if (!isprint(character)) {
                pos = inc(pos, HEXLEN + 7);
                printf("[0x%02x|0%03o]", character,character);
                if (character == '\n')
                    pos = 0;
            } else {
                pos = inc(pos, 1);
                putchar(character);
            }
        }
        putchar('\n');
        putchar('\n');
    }
}
