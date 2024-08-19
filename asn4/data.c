//CS2211a 2023, Section 1
//Assignment number : 4
//Aryan gupta
//251306109
//agupt379
//13th November
// ====== this is in data.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

// Function to construct a Key
Key key_construct(char *in_name, int in_num)
{
    Key new_key;

    // Allocate memory for the name and copy in_name
    new_key.name = malloc(strlen(in_name) + 1);  // +1 for the null terminator
    strcpy(new_key.name, in_name);
    new_key.num = in_num;
    return new_key;
}

// Function to compare two keys
// Returns < 0 if key1 < key2, 0 if key1 = key2, and > 0 if key1 > key2
int key_comp(Key key1, Key key2)
{
    // Compare the names using strcmp
    int cmp;
    cmp = strcmp(key1.name, key2.name);

    // If names are equal, compare the numbers
    if (cmp == 0)
    {
        return key1.num - key2.num;
    }

    return cmp;
}

// Function to print a key
void print_key(Key key)
{
    // Print the number with a width of 5 characters, and left-align the name within 20 characters
    printf("%5d \t%-20s", key.num, key.name);
}

// Function to print a node
void print_node(Node node)
 {
    // Print the key using the print_key function and then print the data
    print_key(node.key);
    printf(" %5d\n", node.data);
}



