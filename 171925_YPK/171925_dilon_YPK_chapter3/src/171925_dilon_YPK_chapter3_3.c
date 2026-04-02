/*
description: Suppose 7 names are stored in an array of pointers names[ ]
        as shown below:
        char *names[ ]= {
        "Santosh",
        "Amol",
        "Santosh Jain",
        "Kishore",
        'Rahul",
        "Amolkumar",
        "Hemant"  };
        Write a program to arrange these names in alphabetical order.
author: Dilon Brahmbhatt
Created: 19 march, 2026
Modified: 19 march, 2026
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
void alpha_sort()
{
    char *names[] = {
        "Santosh",
        "Amol",
        "Santosh Jain",
        "Kishore",
        "Rahul",
        "Amolkumar",
        "Hemant"
    };

    int8_t number = 7;
    int8_t outer_index, inner_index;
    char *temp;

    for (outer_index = 0; outer_index < number - 1; outer_index++)
    {
        for (inner_index = 0; inner_index < number - outer_index - 1; inner_index++)
        {
            if (strcmp(names[inner_index], names[inner_index + 1]) > 0)
            {
                temp = names[inner_index];
                names[inner_index] = names[inner_index + 1];
                names[inner_index + 1] = temp;
            }
        }
    }
    // Print sorted names
    printf("Sorted names:\n");
    for (outer_index = 0; outer_index < number; outer_index++)
    {
        printf("%s\n", names[outer_index]);
    }
}
