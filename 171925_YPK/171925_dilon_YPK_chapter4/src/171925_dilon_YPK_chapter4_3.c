#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Linked list node
struct node {
    char filename[256];
    struct node *next;
};

// Create a new node
struct node* createNode(const char *name) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->filename, name);
    newNode->next = NULL;
    return newNode;
}

// Insert in sorted (alphabetical) order
struct node* sortedInsert(struct node *head, const char *name) {
    struct node *newNode = createNode(name);

    // Insert at beginning if list empty or name comes first
    if (head == NULL || strcmp(name, head->filename) < 0) {
        newNode->next = head;
        return newNode;
    }

    // Find correct position
    struct node *curr = head;
    while (curr->next != NULL && strcmp(name, curr->next->filename) > 0) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// Display the linked list
void displayList(struct node *head) {
    int count = 1;
    printf("\n--- Directory Listing (Alphabetical Order) ---\n");
    while (head != NULL) {
        printf("%d. %s\n", count++, head->filename);
        head = head->next;
    }
    printf("----------------------------------------------\n");
}

// Free memory
void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void f_and_d_short() {
    DIR *dir;
    struct dirent *entry;
    struct node *head = NULL;

    // Open current directory
    dir = opendir(".");
    if (dir == NULL) {
        printf("Error: Cannot open directory.\n");
        return 1;
    }

    // Read all entries and insert into sorted linked list
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files (. and ..)
        if (entry->d_name[0] == '.')
            continue;
        head = sortedInsert(head, entry->d_name);
    }

    closedir(dir);

    // Display sorted list
    displayList(head);

    // Free memory
    freeList(head);
}
