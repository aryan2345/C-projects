
//CS2211a 2023, Section 1
//Assignment number : 4
//Aryan gupta
//251306109
//agupt379
//13th November
// ====== this is a sample main program
#include <stdio.h>
#include <string.h>
#include "bst.h"
int main(void) {
    BStree bst;
    bst = bstree_ini(600);
    bstree_insert(bst, key_construct("Oxford Street", 70), 2500);
    bstree_insert(bst, key_construct("3 Valleys Place", 8), 2000);
    bstree_insert(bst, key_construct("Western Road", 101), 2500);
    bstree_insert(bst, key_construct("3rd Street", 74), 3000);
    bstree_insert(bst, key_construct("4 Oaks Crescent", 4), 2100);
    bstree_insert(bst, key_construct("Abbott Street", 10), 2300);
    bstree_insert(bst, key_construct("1st Street", 100), 1000);
    bstree_insert(bst, key_construct("Beech Drive", 204), 1800);
    bstree_insert(bst, key_construct("Beechbank Crescent", 36), 2400);
    bstree_insert(bst, key_construct("Beechmount Crescent", 36), 2500);
    bstree_insert(bst, key_construct("Oxford Street", 46), 2600);
    bstree_traversal(bst);
    bstree_free(bst);


    BStree MyTree;
    int size;

    // Prompt the user to enter the size of the tree node array
    printf("Enter the size of the tree node array: ");
    scanf("%d", &size);
    getchar(); // consume newline character

    // Initialize the binary search tree
    MyTree = bstree_ini(size);

    // Prompt the user to enter key and data pairs
    printf("Enter key and data pairs, each with two lines:\n");
    printf("  - One line for the key (an int followed by a string with spaces)\n");
    printf("  - The next line with one int for the data\n");

    // Read key and data pairs and insert them into the binary search tree
    int i;
    int number;
    char str[256];
    int data;
    for (i = 0; i < size; ++i)
    {
        // Read key
        printf("Enter key %d:\n", i + 1);
        scanf("%d ", &number);
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // remove newline character

        // Read data
        printf("Enter data for key %d:\n", i + 1);
        scanf("%d", &data);
        getchar(); // consume newline character

        // Insert key and data into the binary search tree
        bstree_insert(MyTree, key_construct(str, number), data);
    }

    // Traverse and print the binary search tree
    bstree_traversal(MyTree);

    // Free the binary search tree
    bstree_free(MyTree);

    return 0;
}

