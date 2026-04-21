/*
description: Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version.
Author: Dilon Brahmbhatt
Created: 16 April, 2026
Modified: 17 April, 2026
*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "header.h"
struct tnode {
    char *word;
        int16_t count;
    struct tnode *left;
    struct tnode *right;
};
/*
description:  talloc: allocate memory for a tree node
Author: Dilon Brahmbhatt
Created: 16 April, 2026
Modified: 17 April, 2026
*/
struct tnode *talloc(void)
{
        struct tnode *p = (struct tnode *) malloc(sizeof(struct tnode));
 
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
 
    return p;
}
 
/*
description: this function takes values from input and create a tree accordingly
Author: Dilon Brahmbhatt
Created: 16 April, 2026
Modified: 17 April, 2026
*/
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}
/*
Description: this function traverse the tree and print the values in accending order.
Author: Dilon Brahmbhatt
Created: 16 April, 2026
Modified: 17 April, 2026
*/
void treeprint(struct tnode *p, int prefix)
{
    static char prev[MAXWORD] = "";
    static int group_active = 0;
 
    if (p != NULL) {
        treeprint(p->left, prefix);
 
        if (strncmp(prev, p->word, prefix) == 0) {
 
            if (!group_active) {
                printf("%s\n", prev);  // print first element
                group_active = 1;
            }
 
            printf("%s\n", p->word);
        }
        else {
            if (group_active)
                printf("\n");
            group_active = 0;
        }
        strcpy(prev, p->word);
        treeprint(p->right, prefix);
    }
}
/*
Description: This function prints the frequecny of the words occurs in the input.
Author: Dilon Brahmbhatt
Created: 16 April, 2026
Modified: 17 April, 2026
*/
void printFrequency(struct tnode *p)
{
    if (p != NULL) {
        printFrequency(p->left);
        printf("%4d %s\n", p->count, p->word);
        printFrequency(p->right);
    }
}
/*
Description: this function groups the similer prefix input.
Author: Dilon Brahmbhatt
Created: 16 April, 2026
Modified: 17 April, 2026
*/
void printGroups(struct tnode *root, int prefix, int flush)
{
    static char prev[MAXWORD] = "";
    static struct tnode *group[100];
    static int count = 0;
 
    if (flush) {
        if (count > 1) {
            printf("\n%s\n", prev);
            for (int8_t index = 0; index < count; index++)
                printf("    %hhd %s\n", group[index]->count, group[index]->word);
        }
        count = 0;
        prev[0] = '\0';
        return;
    }
 
    if (root == NULL) return;
 
    printGroups(root->left, prefix, 0);
 
    char current[MAXWORD];
    strncpy(current, root->word, prefix);
    current[prefix] = '\0';
 
    if (count > 0 && strcmp(prev, current) != 0) {
        if (count > 1) {
            printf("\n%s\n", prev);
            for (int8_t index = 0; index < count; index++)
                printf("    %hhd %s\n", group[index]->count, group[index]->word);
        }
        count = 0;
    }

    strcpy(prev, current);
    group[count++] = root;
    printGroups(root->right, prefix, 0);
}

/*
Description: this function is the main function which handles every supporting functions.
Author: Dilon Brahmbhatt
Created: 16 April, 2026
Modified: 17 April, 2026
*/
int16_t BSTHandlingVariableCount(int16_t argc, char *argv[])
{
    FILE *fp;
    int prefix = 6;
 
    if (argc < 2) {
        printf("Usage: %s file.c [prefix]\n", argv[0]);
        return 1;
    }
    if (argc > 2)
        prefix = atoi(argv[2]);
    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }
    printf("\nC program which you gave as input:\n\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
          fp = fopen(argv[1], "r");
    stdin = fp;
    struct tnode *root = NULL;
    char word[MAXWORD];
    while (mygetword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && binsearch(word, keytab, NKEYS) < 0)
            root = addtree(root, word);
    }

    fclose(fp);
    printf("\nWord Frequency:\n");
    printFrequency(root);
    printf("\nSimilar Words (%d):\n", prefix);
printGroups(root, prefix, 0);
printGroups(NULL, prefix, 1);
    return 0;
}
