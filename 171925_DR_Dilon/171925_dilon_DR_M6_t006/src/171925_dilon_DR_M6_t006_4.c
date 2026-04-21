/*
Description: Write a program that prints the distinct words in its input sorted into decreasing order of frequency of occurrence. Precede each word by its count.
Author: Dilon Brahmbhatt
Created: 17 April, 2026
Modified: 17 April, 2026
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "header.h"
#define MAX_WORDS 10000
struct word_node *word_list[MAX_WORDS];
int16_t word_counting = 0;

/*
Description: This function takes address of each node and store whole tree into an array.
Author: Dilon Brahmbhatt
Created: 17 April, 2026
Modified: 17 April, 2026
*/
void collect_nodes(struct word_node *root) {
    if (root == NULL) return;
    collect_nodes(root->left_child);
    if (word_counting < MAX_WORDS)
        word_list[word_counting++] = root;
    collect_nodes(root->right_child);
}

/*
Description: simple insertion sort fine for typical word-count sizes
Author: Dilon Brahmbhatt
Created: 17 April, 2026
Modified: 17 April, 2026
*/
void display_sorted(void) {
        for (int8_t index = 1; index < word_counting; index++) {
        struct word_node *key = word_list[index];
        int jindex = index - 1;
        while (jindex >= 0 && word_list[jindex]->occurrence_count < key->occurrence_count) {
            word_list[jindex + 1] = word_list[jindex];
            jindex--;
        }
        word_list[jindex + 1] = key;
    }
 
    for (int8_t index = 0; index < word_counting; index++) {
        printf("%hd : %s\n", word_list[index]->occurrence_count, word_list[index]->text);
    }
}
 
 
void SortDecendingOccurence() {
    struct word_node *tree_root = NULL;
    char word_buffer[MAX_STR_LEN];
    int16_t is_filtered;
    while (fetch_next_word(word_buffer, MAX_STR_LEN) != EOF) {
        if (isalpha(word_buffer[0])) {
            is_filtered = find_filter_word(word_buffer, filter_list, TOTAL_FILTER_WORDS);
            if (is_filtered == -1) {
                tree_root = add_word_to_tree(tree_root, word_buffer);
            }
        }
    }
    /* collect all nodes then sort and print */
    collect_nodes(tree_root);
    display_sorted();
}
