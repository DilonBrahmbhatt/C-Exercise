/*
Description: Write a cross-referencer that prints a list of all words in a document, and for each word,
         a list of the line numbers on which it occurs. Remove noise words like ``the,'' ``and,'' and so on.
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

/*
Description: This is the main function which call find_filter_word to find occurence in line.
Author: Dilon Brahmbhatt
Created: 17 April, 2026
Modified: 17 April, 2026
*/

void LinePrintingWithWordCount() {
    struct word_node *tree_root = NULL;
    char word_buffer[MAX_STR_LEN];
    int16_t is_filtered;
clear_input_buffer();
while (fetch_next_word(word_buffer, MAX_STR_LEN) != EOF) {
    if (isalpha(word_buffer[0])) {
        is_filtered = find_filter_word(word_buffer, filter_list, TOTAL_FILTER_WORDS);
        if (is_filtered == -1) {
            tree_root = add_word_to_tree(tree_root, word_buffer);
        }
    }
}
    display_tree_data(tree_root);
}
