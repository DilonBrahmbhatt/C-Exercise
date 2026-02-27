/*
Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly.
C comments don't nest.
Author: Dilon Brahmbhatt
Created: 16 february, 2026
Modified: 16 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

#define MAX 10000
void remove_comments(void)
{
    int16_t current_char, next_char;
    char filename[100];
    FILE *fp_input;
    FILE *fp_output;

    printf("Enter C file name: ");
    scanf("%s", filename);

    fp_input = fopen(filename, "r");

    if (fp_input == NULL)
    {
        printf("Input file not found\n");
        return;
    }

    fp_output = fopen("output.c", "w");

    if (fp_output == NULL)
    {
        printf("Unable to create output file\n");
        fclose(fp_input);
        return;
    }

    while ((current_char = fgetc(fp_input)) != EOF)
    {
        if (current_char == '/')
        {
            next_char = fgetc(fp_input);


            if (next_char == '/')
            {
                while ((current_char = fgetc(fp_input)) != '\n' &&
                       current_char != EOF);

                fputc('\n', fp_output);
            }
            else if (next_char == '*')
            {
                int16_t previous = 0;

                while ((current_char = fgetc(fp_input)) != EOF)
                {
                    if (previous == '*' && current_char == '/')
                        break;

                    previous = current_char;
                }
            }
            else
            {
                fputc(current_char, fp_output);

                if (next_char != EOF)
                    fputc(next_char, fp_output);
            }
        }
        else
        {
            fputc(current_char, fp_output);
        }
    }

    fclose(fp_input);
    fclose(fp_output);

    printf("Comments removed successfully. Output stored in output.c\n");
}
