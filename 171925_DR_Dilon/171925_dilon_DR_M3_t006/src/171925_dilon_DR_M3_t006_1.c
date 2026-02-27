/*
description: Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time
Author: Dilon Brahmbhatt
Created: 24 february, 2026
Modified: 24 february, 2026
*/

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include "header.h"

int16_t binary_search(int16_t target, int16_t array[], int16_t array_size)
{
    int16_t low_index = 0;
    int16_t high_index = array_size - 1;
    int16_t mid_index;
 
    while (low_index < high_index)
    {
        mid_index = (low_index + high_index) / 2;
 
        if (target > array[mid_index])   // Only ONE comparison inside loop
            low_index = mid_index + 1;
        else
            high_index = mid_index;
    }
 
    if (array[low_index] == target)
        return low_index;
    else
        return -1;
}
void sort_array(int16_t arr[], int16_t n)
{
    for (int16_t i = 0; i < n - 1; i++)
    {
        for (int16_t j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int16_t temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void binary_search_main()
{
    int16_t array_size;
    int16_t search_value;
    int16_t last= INT16_MIN;
    bool t=true;
    printf("Enter number of elements: ");
    scanf("%hd", &array_size);
 
    int16_t input_array[array_size];
 
    printf("Enter %hd sorted elements:\n", array_size);
    for (int16_t index = 0; index < array_size; index++)
    {
        scanf("%hd", &input_array[index]);
        if(input_array[index]< last)
         {
           t=false;
         }
     last=input_array[index];
    }
 
    printf("Enter element to search: ");
    scanf("%hd", &search_value);
 
     if(t==false)
     {
      printf("array is not shorted. \n");
       sort_array(input_array, array_size);
 
    printf("Array after sorting:\n");
    for (int16_t i = 0; i < array_size; i++)
        printf("%hd ", input_array[i]);
    printf("\n");
    }
 
    int16_t found_index = binary_search(search_value, input_array, array_size);
 
    if (found_index != -1)
        printf("Element %hd found in array at index %hd\n", search_value, found_index);
    else
        printf("Element %hd not found in array\n", search_value);
}
