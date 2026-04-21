/*  description: undcl program is used to convert a word description of a
        declaration into a C declaration. ensure that the program does not
        add unnecessary parentheses around parts of the declaration.
    Author: Dilon Brahmbhatt
    Created: 13 april, 2026
    Modified: 13 april, 2026
*/
#include <stdio.h>
#include <string.h>
#define MAXTOKEN 100
#define NAME 1000
#define PARENS 1001
#define BRACKETS 1002
int gettoken(void);
extern char token[MAXTOKEN];
void UndclUpdated()
{
    int type;
    char temp[1000];
    char out[1000];
    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n'){
            if (type == PARENS || type == BRACKETS){
                strcat(out, token);
            }
            else if (type == '*') {
                if (strchr(out, '(') != NULL || strchr(out, '[') != NULL) {
                    sprintf(temp, "(*%s)", out);
                } else {
                    sprintf(temp, "*%s", out);
                }
                strcpy(out, temp);
            }
            else if (type == NAME){
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }
}
