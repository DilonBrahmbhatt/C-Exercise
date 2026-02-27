/*
Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent
complete list abc...xyz in s2. Allow for letters of either case and digits and be prepared to handle cases
like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
Author: Dilon Brahmbhatt
Created: 25 february, 2026
Modified: 25 february, 2026
*/
#include <stdio.h>
#include<stdint.h>

void expand(char s1[], char s2[]) {
    int16_t current_index = 0, print_index = 0;

    while (s1[current_index] != '\0') {

        if (current_index > 0 && s1[current_index] == '-' && s1[current_index+1] != '\0') {
            char start = s1[current_index-1];
            char end = s1[current_index+1];

            if (((start >= 'a' && start <= 'z') && (end >= 'a' && end <= 'z')) ||
                ((start >= 'A' && start <= 'Z') && (end >= 'A' && end <= 'Z')) ||
                ((start >= '0' && start <= '9') && (end >= '0' && end <= '9'))) {

                if (start < end) {
                    char next = start ;
                    while (next < end) s2[print_index++] = next++;
                }
		else if (start > end) {
                    char next = start ;
                    while (next > end) s2[print_index++] = next--;
                }

            } else {

                s2[print_index++] = s1[current_index];
            }
        } else {

            s2[print_index++] = s1[current_index];
        }
        current_index++;
    }
    s2[print_index] = '\0';
}

void expand_main() {
    char input[100], output[500];

    printf("Enter shorthand string: ");
    scanf("%s", input);

    expand(input, output);
    printf("Expanded: %s\n", output);

}
