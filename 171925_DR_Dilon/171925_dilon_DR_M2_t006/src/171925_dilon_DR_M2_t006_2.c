#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 1000

void get_input_no_logic_ops() {
    char s[MAX_LIMIT];
    int16_t i, c;
    int loop_active = 1;

    printf("Enter your text (Press Enter or Ctrl+D to finish):\n");

    // The loop rewritten without && or ||
    for (i = 0; loop_active == 1; i++) {
        // 1. Check if we have space in the buffer
        if (i >= MAX_LIMIT - 1) {
            loop_active = 0;
        } else {
            c = getchar();
            // 2. Check for End of File (Ctrl+D / Ctrl+Z)
            if (c == EOF) {
                loop_active = 0;
            }
            // 3. Check for Newline (Enter key)
            else if (c == '\n') {
                loop_active = 0;
            } 
            // 4. If all clear, save the character
            else {
                s[i] = c;
            }
        }
    }

    s[i-1] = '\0'; 

    printf("%s\n", s);
}
