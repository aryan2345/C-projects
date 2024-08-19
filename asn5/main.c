// main.c
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STREET_LENGTH 100

int main()
{
    // creates a new Matrix
    Matrix matrix = matrix_construction();

    // reads from stdin
    int num;
    char street[MAX_STREET_LENGTH];
    while (scanf("%d %[^\n]", &num, street) != EOF)
    {
        Index1 index1;
        Index2 index2;

        // Allocate memory for index1 and copy the string
        index1 = (Index1)malloc(strlen(street) + 1);
        if (index1 != NULL)
        {
            strcpy(index1, street);
        }

        index2 = num;

        // checks if the location is defined in Matrix
        if (matrix_index_in(matrix, index1, index2))
        {
            // if location is defined, get the pointer to the associated value
            const Value* trial = matrix_get(matrix, index1, index2);
            Value* value;
            value = (Value*)trial;
            // if the pointer is not NULL, increment the value
            if (value != NULL)
            {
                (*value)++;
            }
        }
        else
        {
            // if location is not defined, set the value to 1
            matrix_set(matrix, index1, index2, 1);
        }

        // frees memory allocated for index1 (string)
        free(index1);
    }

    // prints the data in the Matrix
    printf("Number\t\tStreet\t  \t\tOccurrence\n");
    matrix_list(matrix);

    // frees all allocated memory spaces for the Matrix
    matrix_destruction(matrix);

    return 0;
}


