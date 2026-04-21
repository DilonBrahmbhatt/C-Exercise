/*
discribtion: Extend entab and detab to accept the shorthand.
                entab -m +n
Author: Dilon Brahmbhatt
Created: 07 april, 2026
Modified: 07 april, 2026
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "header.h"

void detab_using_custom_column(int16_t start_col)
{
    int16_t ch;
    int16_t index = 1;
    int16_t space_count = 0;
    int16_t TABSIZE=4;
    printf("press ctrl + D to escape the string\n");
    printf("Enter the String: ");

    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ')
        {
            space_count++;
            continue;
        }

        /* If space sequence ended */
        if (space_count > 0)
        {
            int16_t needed = (TABSIZE - ((index - start_col) % TABSIZE)) % TABSIZE;
                 space_count = needed;
            for (int i = 0; i < space_count; i++)
            {
                putchar('*');
                index++;
            }

            space_count = 0;
        }

        if (ch == '\t')
        {
            int16_t spaces = TABSIZE - ((index - 1) % TABSIZE);
            for (int i = 0; i < spaces; i++)
            {
                putchar('*');
                index++;
            }
        }
        else
        {
            putchar(ch);
            if (ch == '\n')
                index = 1;
            else
                index++;
        }
    }
}

void etab_using_custom_column(int16_t start_col)
{
    int16_t ch;
        int16_t index;
    int8_t space_count=0;
    printf("press ctrl + D to escape the string\n");
    printf("Enter the String: ");
    int16_t TABSIZE=4;
    while ((ch = getchar()) != EOF)
        {
          if(ch == 32)
           {
                space_count++;
                if(space_count==TABSIZE)
                 {
                        space_count=0;
                        //putchar('/');
                        //putchar('t');
			putchar('#');
                 }
           }
          else if(ch == 9)
           {
                 //putchar('/');
                 //putchar('t');
		putchar('#');
                space_count=0;
           }
          else
           {
                        while(space_count>0)
                         {
                                //putchar(32);
                                putchar('*');
                                space_count--;
                         }
                        putchar(ch);
           }
        }
        putchar(10);
}

void ShortHandDetabEntab(int16_t argc, char *argv[])
{
    if (argc >= 4)
    {
        int16_t TABSIZE=4;
        int16_t start_col = abs(atoi(argv[2]));
        TABSIZE = atoi(argv[3]);

     if (strcmp(argv[1], "de") == 0)
         {
            detab_using_custom_column(start_col);
        }
      else if (strcmp(argv[1], "en") == 0)
           {
            etab_using_custom_column(start_col);
        }
      else
          {
            printf("Invalid emtry!!!!\n");
        }
       }
    else
       {
        printf("Usage: ./program [-m/+n] [n]\n");
    }
}
