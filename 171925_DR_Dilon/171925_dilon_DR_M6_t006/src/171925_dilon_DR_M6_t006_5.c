/*
Description: Write a function undef that will remove a name and definition from the table maintained by lookup and install.
Author: Dilon Brahmbhatt
Created: 17 April, 2026
Modified: 17 April, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
static struct nlist *hashtab[HASHSIZE];
/*
Description: This is a hash function which found the index to store list.
Author: Dilon Brahmbhatt
Created: 20 April, 2026
Modified: 20 April, 2026
*/
unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

/*
Description: install function iterate through hash table then linklist to find appropriate place.
Author: Dilon Brahmbhatt
Created: 20 April, 2026
Modified: 20 April, 2026
*/
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free(np->defn);
    }

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/*
Description: this function deletes the required entry.
Author: Dilon Brahmbhatt
Created: 20 April, 2026
Modified: 20 April, 2026
*/
struct nlist *undef(char *name) {
    unsigned hashval = hash(name);
    struct nlist *curr = hashtab[hashval];
    struct nlist *prev = NULL;

    while (curr != NULL) {
        if (strcmp(name, curr->name) == 0) {
            if (prev == NULL)
                hashtab[hashval] = curr->next;
            else
                prev->next = curr->next;

            free(curr->name);
            free(curr->defn);
            free(curr);
            return NULL;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}
 
/*
Description: This is function print the hash table.
Author: Dilon Brahmbhatt
Created: 20 April, 2026
Modified: 20 April, 2026
*/
void print_table() {
    int16_t index;
    struct nlist *np;

    for (index = 0; index < HASHSIZE; index++) {
        for (np = hashtab[index]; np != NULL; np = np->next) {
            printf("%-15s %s\n", np->name, np->defn);
        }
    }
}

/*
Description: this functions act as a main function an call other needed fucntions.
Author: Dilon Brahmbhatt
Created: 20 April, 2026
Modified: 20 April, 2026
*/
void InstallUndef() {
    int16_t num, index;
    char name[MAX], defn[MAX];

    printf("Enter number of entries: ");
    scanf("%hd", &num);
    getchar();

    for (index = 0; index < num; index++) {
        printf("\nName : ");
        fgets(name, MAX, stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Definition : ");
        fgets(defn, MAX, stdin);
        defn[strcspn(defn, "\n")] = 0;

        install(name, defn);
    }

    printf("\nOutput:\n\n");
    print_table();

    printf("\nRemove Entry : ");
    fgets(name, MAX, stdin);
    name[strcspn(name, "\n")] = 0;

    undef(name);

    printf("\nAfter Deletion:\n\n");
    print_table();
}
