/*
Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
Author: Dilon Brahmbhatt
Created: 11 february, 2026
Modified: 11 february, 2026
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void word_length_histogram()
{
  int16_t current_char;
  char ans[100];
  bool p_char=true;
  int8_t length=0;
  while ((current_char = getchar()) != EOF && length<99)
   {
    if(current_char == 32 || current_char == 9 ||current_char == 10 )
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
      ans[length]='*';
      length++;
     }
   }
  ans[length]='\0';
 printf("\n%s\n",ans);
}
