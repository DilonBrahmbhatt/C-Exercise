/*
description: Write a program to find determinant value of a two-
             dimensional matrix of any given size (n x n).
       Hint: Use recursion and the standard library function calloc()
             for dynamic allocation of memory.
author: Dilon Brahmbhatt
Created: 24 march, 2026
Modified: 24 march, 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
description: this function creates submatrixs from existing matrix.
author: Dilon Brahmbhatt
Created: 24 march, 2026
Modified: 24 march, 2026
*/
void getMinor(int16_t **matrix, int16_t **subMatrix, int8_t skipRow, int8_t skipCol, int8_t size)
{
        int8_t subRow = 0, subCol = 0;
    for (int8_t row = 0; row < size; row++)
    {
        if (row == skipRow)
        {
            continue;
        }
          subCol = 0;
        for (int8_t col = 0; col < size; col++)
        {
            if (col == skipCol)
            {
                continue;
            }
        subMatrix[subRow][subCol] = matrix[row][col];
         subCol++;
        }
        subRow++;
    }
}
/*
description: this function get the matrix and submatrix then calculate the determinent.
author: Dilon Brahmbhatt
Created: 24 march, 2026
Modified: 24 march, 2026
*/
int16_t determinant(int16_t **matrix, int8_t size)
{
     int8_t result = 0;
    if (size == 1)
         return matrix[0][0];
       if (size == 2)
           return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    int8_t sign = 1;
       int16_t **subMatrix = (int16_t **)calloc(size - 1, sizeof(int16_t *));
    for (int8_t index = 0; index < size - 1; index++)
        subMatrix[index] = (int16_t *)calloc(size - 1, sizeof(int16_t));
            for (int8_t col = 0; col < size; col++)
        {
         getMinor(matrix, subMatrix, 0, col, size);
        result += sign * matrix[0][col] * determinant(subMatrix, size - 1);
        sign = -sign;
    }
      for (int8_t index = 0; index < size - 1; index++)
          free(subMatrix[index]);
        free(subMatrix);
        return result;
}
/*
description: this is a main function which calls determinent
             function and pass the matrix and other parameters.
author: Dilon Brahmbhatt
Created: 24 march, 2026
Modified: 24 march, 2026
*/
void determinantFind()
{
    int8_t size;
    printf("Enter size: ");
    scanf("%hhd", &size);
        int16_t **matrix = (int16_t **)calloc(size, sizeof(int16_t *));
      for (int8_t index = 0; index < size; index++)
         matrix[index] = (int16_t *)calloc(size, sizeof(int16_t));
     printf("Enter elements:\n");
     for (int8_t row = 0; row < size; row++)
          for (int8_t col = 0; col < size; col++)
              scanf("%hd", &matrix[row][col]);
      int8_t detValue = determinant(matrix, size);
      printf("Determinant = %d\n", detValue);
     for (int8_t index = 0; index < size; index++)
         {
                free(matrix[index]);
        }
       free(matrix);
}

