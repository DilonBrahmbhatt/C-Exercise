/*
description: Write a pointer version of the function strcat that we showed in Chapter 2:
                strcat(s,t) copies the string t to the end of s.
author: Dilon Brahmbhatt
created date: 30-03-2026
modified date: 30-03-2026
*/
#include<stdio.h>
#include<ctype.h>
#include "header.h"
/* strcat: concatenate t to end of s; s must be big enough */
void strcatModidied(char s1ptr[], char s2ptr[]) {
     while (*s1ptr != '\0')
        s1ptr++;
    s1ptr--;             /* goes back to \0 char */
    while ((*s1ptr = *s2ptr) != '\0') {
        s1ptr++;
        s2ptr++;
    }
}
void strcatMain(){
clear_input_buffer();
    char string1[MAXLINE], string2[MAXLINE];
printf("enter string S :");
        mgetline(string1, MAXLINE);
printf("enter string T :");
        mgetline(string2, MAXLINE);
    strcatModidied(string1, string2);
printf("combined string :");
    printf("%s", string1);
}
