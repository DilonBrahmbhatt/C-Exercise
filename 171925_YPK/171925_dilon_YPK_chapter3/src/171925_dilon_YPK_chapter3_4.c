/*
description: Write a program to compress any given string such that the
        multiple blanks present in it are eliminated. Store the
        compressed message in another string. Also write a
        decompressant program to get back the original string with all
        its spaces restored.
        The uncompressed string can be:
        "Imperial Palace. Rome. Attention Julius Caesar. Dear Caesar, we
        have the clarification you requested. Details to follow by courier.
        Meanwhile stay clear of Brutus."
author: Dilon Brahmbhatt
Created: 19 march, 2026
Modified: 19 march, 2026
*/
#include <stdio.h>
#include <stdint.h>
#define MAX 500
/*
description: this is the compression function which remove multiple blanks
author: Dilon Brahmbhatt
Created: 19 march, 2026
Modified: 19 march, 2026
*/
void compress(char *original, char *compressed, char spaceCount[], int *countSize)
{
    int i = 0, j = 0;
    while (original[i] != '\0')
    {
        if (original[i] == ' ')
        {
            int count = 0;
            while (original[i] == ' ')
            {
                count++;
                i++;
            }
            compressed[j++] = ' ';
            spaceCount[*countSize] = (char)(count - 1);
            (*countSize)++;
        }
        else
        {
            compressed[j++] = original[i++];
        }
    }
    compressed[j] = '\0';
}
/*
description: this is the compression function which remove multiple blanks
author: Dilon Brahmbhatt
Created: 19 march, 2026
Modified: 19 march, 2026
*/
void decompress(char *compressed, char *decompressed, char spaceCount[], int countSize)
{
    int i = 0, j = 0, k = 0;
    while (compressed[i] != '\0')
    {
        if (compressed[i] == ' ')
        {
            decompressed[j++] = ' ';
            int extra = spaceCount[k++];
            for (int x = 0; x < extra; x++)
            {
                decompressed[j++] = ' ';
            }
            i++;
        }
        else
        {
            decompressed[j++] = compressed[i++];
        }
    }
    decompressed[j] = '\0';
}
void compressed_decompressed()
{
    char original[MAX] = "Imperial   Palace.  Rome.   Attention Julius   Caesar.";
    char compressed[MAX];
    char decompressed[MAX];
    char spaceCount[MAX];
    int countSize = 0;
    compress(original, compressed, spaceCount, &countSize);
    printf("Original:\n%s\n\n", original);
    printf("Compressed:\n%s\n\n", compressed);
    decompress(compressed, decompressed, spaceCount, countSize);
    printf("Decompressed:\n%s\n", decompressed);
}
