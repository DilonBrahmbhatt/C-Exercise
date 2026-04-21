/*
description:Write versions of the library functions strncpy, strncat, and strncmp,
                 which operate on at most the first n characters of their argument
                strings. For example, strncpy(s,t,n) copies at most n characters of t to s.
                Full descriptions are in Appendix B.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 30-03-2026
*/
#include<stdio.h>
#include<ctype.h>
#include<stdint.h>
#include "header.h"
/*
description: this is string copy function using pointers
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 30-03-2026
*/
char *strncpy(char *dest, const char *src, size_t n)
    {
        for(int8_t index = 0; index<n && *src != '\0'; index++){
            *dest++ = *src++;
        }
        return &dest;
    }
/*
description: this is string concatination function using pointers.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 30-03-2026
*/
char *strncat(char *dest, const char *src, size_t n)
{
    while(*dest != '\0')
    {
        *dest++;
    }
    for(int8_t index = 0; index<n && *src != '\0'; index++){
            *dest++ = *src++;
        }
}
/*
description: this is string comparison function using pointers.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 30-03-2026
*/
int8_t strncmp(const char *dest, const char *src, size_t n){
    while(*src != '\0' && n > 1 && *src == *dest){
        dest++;
        src++;
        n--;
    }
    return *dest - *src;
}
/*
description: this is the main function of program which handle input outputs.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 30-03-2026
*/
void cpy_Cmp_Cat()
{
    char str1[MAXLINE];
    char str2[MAXLINE];
int8_t result;
int8_t choose;
int8_t num;
    clear_input_buffer();
    printf("Enter a string: ");
    mgetline(str1, MAXLINE);
    printf("Enter substring to search: ");
    mgetline(str2, MAXLINE);
printf("Enter the Size : ");
scanf("%hhd", &num);
        printf("1. copy string! \n");
        printf("2. concat string! \n");
        printf("3. compare string! \n");
        printf("Enter the operation Number :");
        scanf("%hhd", &choose);
        switch(choose){
                case 1: strncpy(str1, str2, num);
                        printf("result: %s\n\n", str1);
                        break;
                case 2: strncat(str1, str2, num);
                        printf("result: %s\n\n", str1);
                        break;
                case 3:
                        {
                        result = strncmp(str1, str2, num);
                        if(result>0)
                        {
                        result = 1;
                        printf("result: match not found \n");
                                }else if(result < 0)
                        {
                        result = -1;
                                printf("result: match not found \n");
                                }
                        else{
                                printf("result: match found \n");
                        }
                        printf("cat (n): %d\n\n", result);
                         break;
                        }
                case 0: exit(0);
                default: printf("Invalid selection.\n");
}
}
