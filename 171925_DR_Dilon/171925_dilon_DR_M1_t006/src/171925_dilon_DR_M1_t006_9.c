/*
copy its input to its output, replacing each string of one or more blanks by a single blank.
Author: Dilon Brahmbhatt
Created: 09 february, 2026
Modified: 10 february, 2026
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void replacing_each_string_of_one_or_more_blanks_by_single_blank()
{
  int16_t ch;
  char ans[100];
  bool p_char=false;
  int8_t length=0;
  while ((ch = getchar()) != EOF && length<100)
   {
    if(ch == 32 || ch == 9)
     {
      if(p_char==false)
       {
        ans[length]=' ';
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
