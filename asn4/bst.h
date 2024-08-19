//CS2211a 2023, Section 1
//Assignment number : 4
//Aryan gupta
//251306109
//agupt379
//13th November
#include "data.h"

typedef struct {
    Node *tree_nodes;
    unsigned char *is_free;
    int size;
} BStree;

BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key key, int data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);


