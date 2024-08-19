// matrix.c
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// a constructor for Matrix
Matrix matrix_construction(void)
{
    // creates a new Key
    return bstree_ini();
}

// checks if a value exists at the specified indices in the matrix
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2)
{
    // creates a new Key
    Key key;
    key = key_ini();
    // sets the indices in the Key
    key_set(key, index1, index2);
    // searches for the Key in the matrix
    Data result = bstree_search(m, key);
    // frees the allocated Key
    key_free(key);
    // returns 1 if the value exists, else 0
    return (result != NULL) ? 1 : 0;
}

// gets a pointer to the value at the specified indices in the matrix
const Value* matrix_get(Matrix m, Index1 index1, Index2 index2)
{
    // creates a new Key
    Key key = key_ini();
    // sets the indices in the Key
    key_set(key, index1, index2);
    // searches for the Key in the matrix
    Data result = bstree_search(m, key);
    // frees the allocated Key
    key_free(key);
    // returns a pointer to the value, or NULL if not found
    return result;
}

// sets a value at the specified indices in the matrix
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value)
{
    // creates a new Key
    Key key = key_ini();
    // sets the indices in the Key
    key_set(key, index1, index2);
    // creates a new Data
    Data data = data_ini();
    // sets the value in the Data
    data_set(data, value);
    // inserts the Key-Data pair into the matrix
    bstree_insert(m, key, data);
}

// prints the contents of the matrix
void matrix_list(Matrix m)
{
    // traverses and print the binary search tree
    bstree_traverse(m);
}

// destructor for Matrix
void matrix_destruction(Matrix m)
{
    // frees the memory allocated for the binary search tree
    bstree_free(m);
}


