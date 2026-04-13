/*Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.
Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should
be given preference?
Author: Dilon Brahmbhatt
Created: 13 february, 2026
Modified: 13 february, 2026
*/
#include <stdio.h>
#include <stdint.h>

void entab_input_text_stream()
{
    int16_t ch;
    int8_t space_count=0;
    printf("press ctrl + D to escape the string\n");
    printf("Enter the String: ");

    while ((ch = getchar()) != EOF)
	{
	  if(ch == 32)
           {
		space_count++;
		if(space_count==8)
		 {
			space_count=0;
			putchar('/');
			putchar('t');
		 }
	   }
	  else if(ch ==9)
	   {
		 putchar('/');
                 putchar('t');
		space_count=0;
	   }
	  else
	   {
			while(space_count>0)
			 {
				putchar(32);
				space_count--;
			 }
			putchar(ch);
	   }
	}
	putchar(10);
}

