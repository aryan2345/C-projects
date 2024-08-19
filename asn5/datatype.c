// datatype.c
#include "datatype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize and allocate memory for a Data element
Data data_ini()
{
    Data data;
    data = (Data)malloc(sizeof(float));
    if (data != NULL)
    {
         // Set the initial value to 0.0
        *data = 0.0;
    }
    return data;
}

// Set the value of a Data element
void data_set(Data data, float intdata)
{
    // Set the value of the Data element
    *data = intdata;
}

// Print the value of a Data element
void data_print(Data data)
{
    // Print the integer value of the Data element
    printf("\t%d", (int)*data);

}

// Free the memory allocated for a Data element
void data_free(Data data)
{
    // Free the memory allocated for the Data element
    free(data);
}

// Initialize and allocate memory for a Key element
Key key_ini()
{
    Key key;
    key = (Key)malloc(sizeof(Key_struct));
    if (key != NULL)
    {
        // Initialize key1 as NULL
        key->key1 = NULL;
        // Initialize key2 as 0
        key->key2 = 0;
    }
    return key;
}

void key_set(Key key, Key1 key1, Key2 key2)
{
    // allocates the memory
    key->key1 = malloc(strlen(key1) + 1);
    if (key->key1 != NULL)
    {
         // copies the string
        strcpy(key->key1, key1);
    }
    // sets key2
    key->key2 = key2;
}


// Compare two Key elements
int key_comp(Key key1, Key key2)
{
    // Compare key1 strings
    int cmp = strcmp(key1->key1, key2->key1);
    if (cmp == 0)
    {
        // If key1 strings are equal, compare key2 integers
        cmp = key1->key2 - key2->key2;
    }
    return cmp;
}

// Print the values of a Key element in the format (key1, key2)
void key_print1(Key key)
{
    printf("(%s, %d)", key->key1, key->key2);
}

// Print the values of a Key element in the format (key2, key1)
void key_print2(Key key)
{
    printf("(%d, %s)", key->key2, key->key1);
}

// Free the memory allocated for a Key element
void key_free(Key key)
{
    // Free the memory allocated for key1
    free(key->key1);
    // Free the memory allocated for the Key element
    free(key);
}


