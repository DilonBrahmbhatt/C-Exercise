/*
a program that prints its input one word per line
Author: Dilon Brahmbhatt
Created: 11 february, 2026
Modified: 11 february, 2026
*/
#include<stdio.h>
#include <stdbool.h>
#include <stdint.h>

void display_words_linewise()
{
  int16_t ch;
  char ans[100];
  bool p_char=true;
  int8_t length=0;
  while ((ch = getchar()) != EOF && length<100)
   {
    if(ch == 32 || ch == 9 ||ch == 10 )
     {
      if(p_char==false)
       {
        ans[length]=10;
        length++;
       }
     p_char=true;
     }
    else
     {p_char=false;
      ans[length]=ch;
      length++;
     }
   }
  ans[length]='\0';
 printf("\n%s\n",ans);
}
