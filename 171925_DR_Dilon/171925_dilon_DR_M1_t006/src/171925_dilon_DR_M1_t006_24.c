#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void check_c_syntax() {
    int16_t current_char, next_char;
    char filename[100];
    FILE *fp_input;

    // Stack variables
    char stack[1000];
    int16_t top = -1;

    printf("Enter C file name: ");
    scanf("%s", filename);

    fp_input = fopen(filename, "r");
    if (fp_input == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    while ((current_char = fgetc(fp_input)) != EOF) {

        // 1. Handle Comments
        if (current_char == '/') {
            next_char = fgetc(fp_input);
            if (next_char == '/') { // Single-line comment
                while ((current_char = fgetc(fp_input)) != EOF && current_char != '\n');
            } else if (next_char == '*') { // Multi-line comment
                while ((current_char = fgetc(fp_input)) != EOF) {
                    if (current_char == '*') {
                        if ((next_char = fgetc(fp_input)) == '/') break;
                        else ungetc(next_char, fp_input);
                    }
                }
            } else {
                ungetc(next_char, fp_input);
            }
        }

        // 2. Handle Strings and Character Literals
        else if (current_char == '"' || current_char == '\'') {
            char quote_type = current_char;
            while ((current_char = fgetc(fp_input)) != EOF) {
                if (current_char == '\\') { // Handle escape sequence (e.g., \")
                    fgetc(fp_input); 
                } else if (current_char == quote_type) {
                    break;
                }
            }
        }

        // 3. Handle Brackets/Braces/Parentheses
        else if (current_char == '(' || current_char == '{' || current_char == '[') {
            if (top < 999) stack[++top] = current_char;
        }
        else if (current_char == ')' || current_char == '}' || current_char == ']') {
            if (top == -1) {
                printf("Error: Unmatched closing bracket '%c' found.\n", current_char);
                fclose(fp_input);
                return;
            }

            char open = stack[top--];
            if ((current_char == ')' && open != '(') ||
                (current_char == '}' && open != '{') ||
                (current_char == ']' && open != '[')) {
                printf("Error: Mismatched bracket. Found '%c' but expected match for '%c'.\n", current_char, open);
                fclose(fp_input);
                return;
            }
        }
    }

    // Final Validation
    if (top == -1) {
        printf("Syntax Check Passed: All brackets and quotes are balanced.\n");
    } else {
        printf("Error: Unclosed bracket '%c' remains at end of file.\n", stack[top]);
    }

    fclose(fp_input);
}
