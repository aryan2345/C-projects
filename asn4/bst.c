//CS2211a 2023, Section 1
//Assignment number : 4
//Aryan gupta
//251306109
//agupt379
//13th November
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Function to initialize a binary search tree (BST)
BStree bstree_ini(int size)
{
    // Initializing a BST data structure named 'bst'
    BStree bst;

    // Allocating memory for a Node array of size+1 for member tree_nodes
    bst.tree_nodes = (Node*)malloc((size+1) * sizeof(Node));

    // Allocating memory for an unsigned char array of size+1 for member is_free
    bst.is_free = (unsigned char*)malloc((size+1) * sizeof(unsigned char));

    int i;

    // Set all entries of is_free to 1 (indicating all positions are initially free)
    for(i = 0 ; i <= size; i++)
    {
        bst.is_free[i] = 1;
    }

    // Setting member size to 'size'
    bst.size = size;

    // Returning a BST
    return bst;
}

// Helper function for recursive insertion into the bst.
void bstree_insert_helper(BStree bst, int i, Key key, int data)
{
    if (i <= bst.size) {
        if (bst.is_free[i]) {
            // Insert the key and data at the current position
            bst.tree_nodes[i].key = key;
            bst.tree_nodes[i].data = data;
            bst.is_free[i] = 0; // Mark as used
        } else {
            // Compare keys to determine the direction of insertion
            int cmp;
            cmp = key_comp(key, bst.tree_nodes[i].key);
            if (cmp < 0) {
                // If key is smaller, move to the left child
                bstree_insert_helper(bst, 2 * i, key, data);
            } else if (cmp > 0) {
                // If key is larger, move to the right child
                bstree_insert_helper(bst, 2 * i + 1, key, data);
            }
        }
    }
    else
    {
        if(i > bst.size)
        {
            printf("Error: Tree is already full. Unable to insert (%s, %d, %d)\n", key.name, key.num, data);
        }
    }
}

// Function to insert a key and data into the bst.
void bstree_insert(BStree bst, Key key, int data) {
    // Start the recursive insertion from the root (position 1)
    bstree_insert_helper(bst, 1, key, data);
}

// Helper function for recursive traversal of the bst.
void bstree_traversal_helper(BStree bst, int i) {
    if (i <= bst.size) {
        if (!bst.is_free[i]) {
            // In-order traversal: left child, current node, right child
            bstree_traversal_helper(bst, 2 * i);
            print_node(bst.tree_nodes[i]);
            bstree_traversal_helper(bst, 2 * i + 1);
        }
    }
}
// Function to perform an in-order traversal of the bst.
void bstree_traversal(BStree bst)
{
    // Start the recursive traversal from the root which is 1.
    bstree_traversal_helper(bst, 1);
}



// Function to free the memory allocated for the bst.
void bstree_free(BStree bst)
{
    free(bst.tree_nodes);
    free(bst.is_free);
}


