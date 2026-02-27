/*
description: Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
Author: Dilon Brahmbhatt
Created: 24 february, 2026
Modified: 24 february, 2026

*/

#include <stdio.h>
#include <stdint.h>
#define MAX 1000

void escape(char s[], char t[])

{

    int16_t index_S = 0, index_T = 0;
 
    while (s[index_S] != '\0')

    {

      switch (s[index_S])

          {

            case '\n':

               t[index_T++] = '\\';

                t[index_T++] = 'n';

              break;
 
          case '\t':

                t[index_T++] = '\\';

               t[index_T++] = 't';

              break;
 
           default:

               t[index_T++] = s[index_S];

                break;

        }

        index_S++;

    }

    t[index_T] = '\0';

}
 
void replace_newline_tab()

{

    char s[MAX];

   char t[MAX];
 
   int16_t ch, index = 0;

  while (1)

    {

        ch = getchar();

        if (ch == '\n')

            break;

    }

    printf("--------press ctrl + D to escape the string--------");

printf("\nEnter the String: ");
 
    while ((ch = getchar()) != EOF && index < MAX - 1)

    {

        s[index++] = ch;

}

    s[index] = '\0';
 
    escape(s, t);
 
    printf("\nConverted String:\n%s\n", t);

}
 
