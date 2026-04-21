/*
discribtion:Modify the program entab and detab (written as exercises in Chapter 1) to accept a list of tab stops as arguments.
            Use the default tab settings if there are no arguments.
Author: Dilon Brahmbhatt
Created: 07 april, 2026
Modified: 07 april, 2026
*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "header.h"
void HandleEntabDetabArgs(int16_t argc, char *argv[])
{
    if (argc >= 3)
    {
       int TABSIZE = atoi(argv[2]);

     if (strcmp(argv[1], "de") == 0)
         {
            detab_input_stream(TABSIZE);
        }
      else if (strcmp(argv[1], "en") == 0)
           {
            entab_input_text_stream();
        }
      else
          {
            printf("Invalid emtry!!!!\n");
        }
       }
    else
       {
        printf("Usage: ./program [en/de] [n]\n");
    }
}
