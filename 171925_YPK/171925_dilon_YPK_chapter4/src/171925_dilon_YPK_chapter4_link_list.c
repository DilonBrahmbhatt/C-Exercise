/*
description: this file contain all the operations related to single linked list.
author: Dilon Brhmbhatt
Created: 25 march, 2026
Modified: 25 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* Structure representing a single node in the list */
struct Node {
    int16_t data;
    struct Node *next;
};

void append(struct Node **header, int16_t num);
void addAtBeg(struct Node **header, int16_t num);
void addAfter(struct Node *header, int16_t location, int16_t num);
void display(struct Node *header);
int16_t count(struct Node *header);
void deleteNode(struct Node **header, int16_t num);

void linkedList_operations() {
    struct Node *header = NULL; // Initialize empty list

    printf("\nNo. of elements in the Linked List = %d", count(header));

    append(&header, 1);
    append(&header, 2);
    append(&header, 3);
    append(&header, 4);
    append(&header, 17);
 
    printf("\nInitial list:");
    display(header);
 
    addAtBeg(&header, 999);
    addAtBeg(&header, 888);
    addAtBeg(&header, 777);
 
    printf("\nAfter adding at beginning:");
    display(header);
 
    addAfter(header, 7, 0);
    addAfter(header, 2, 1);
    addAfter(header, 1, 99);
 
    printf("\nAfter adding after specific locations:");
    display(header);
    printf("\nNo. of elements = %d", count(header));
 
    deleteNode(&header, 888);
    deleteNode(&header, 1);
    deleteNode(&header, 10);
 
    printf("\nAfter deletions:");
    display(header);
    printf("\nNo. of elements = %d\n", count(header));
}
 
/* Adds a node at the very end of the list */
void append(struct Node **header, int16_t num) {
    struct Node *newNode, *current;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
 
    if (*header == NULL) {
        *header = newNode;
    } else {
        current = *header;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
 
/* Adds a node at the start of the list */
void addAtBeg(struct Node **header, int16_t num) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
 
    newNode->data = num;
    newNode->next = *header;
    *header = newNode;
}
 
/* Adds a node after 'loc' number of nodes */
void addAfter(struct Node *header, int16_t loc, int16_t num) {
    struct Node *newNode, *current;
    current = header;
 
    for (int8_t index = 0; index < loc; index++) {
        if (current == NULL) {
            printf("\nThere are less than %d elements in list", loc);
            return;
        }
        current = current->next;
    }
 
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = current->next;
    current->next = newNode;
}
 
/* Prints all elements in the list */
void display(struct Node *header) {
    struct Node *current = header;
    printf("\nList: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
 
/* Counts the number of nodes */
int16_t count(struct Node *header) {
    int8_t c = 0;
    struct Node *current = header;
    while (current != NULL) {
        current = current->next;
        c++;
    }
    return c;
}
 
/* Deletes a node by its value */
void deleteNode(struct Node **header, int16_t num) {
    struct Node *previous, *current;
    current = *header;
 
    while (current != NULL) {
        if (current->data == num) {
            if (current == *header) {
                *header = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("\nElement %d not found", num);
}
