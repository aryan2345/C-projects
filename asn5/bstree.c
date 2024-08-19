// bstree.c
#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

// creates a new node with the given key and data
BStree_node* new_node(Key key, Data data)
{
    BStree_node* node;
    node = (BStree_node*)malloc(sizeof(BStree_node));
    if (node != NULL)
    {
        node->key = key;
        node->data = data;
        node->left = node->right = NULL;
    }
    return node;
}

// initialize a binary search tree
BStree bstree_ini(void)
{
    BStree bst = (BStree)malloc(sizeof(BStree_node*));
    if (bst != NULL)
    {
        *bst = NULL;
    }
    return bst;
}

// helper function for inserting a key-data pair into the binary search tree
void bstree_insert_helper(BStree_node** root, Key key, Data data)
{
    int cmp;
    if (*root == NULL)
    {
        *root = new_node(key, data);
    }
    else
    {
        cmp = key_comp(key, (*root)->key);
        if (cmp > 0)
        {
            bstree_insert_helper(&(*root)->right, key, data);
        }
        else if (cmp < 0)
        {
            bstree_insert_helper(&(*root)->left, key, data);
        }

    }
}

// inserts a key-data pair into the binary search tree
void bstree_insert(BStree bst, Key key, Data data)
{
    bstree_insert_helper(bst, key, data);
}

// helper function for searching a key in the binary search tree
Data bstree_search_helper(BStree_node* root, Key key)
{
    if (root == NULL)
    {
        return NULL;
    }
    int cmp;
    cmp = key_comp(key, root->key);
    if (cmp == 0)
    {
        return root->data;
    }
    else if (cmp < 0)
    {
        return bstree_search_helper(root->left, key);
    }
    else
    {
        return bstree_search_helper(root->right, key);
    }
}

// searches for a key in the binary search tree and return the associated data
Data bstree_search(BStree bst, Key key)
{
    return bstree_search_helper(*bst, key);
}

// helper function for traversing and printing the binary search tree
void bstree_traverse_helper(BStree_node* root)
{
    if (root != NULL)
    {
        bstree_traverse_helper(root->left);
        printf("%-15d %-20s ", root->key->key2, root->key->key1);
        data_print(root->data);
        printf("\n");
        bstree_traverse_helper(root->right);
    }
}

// traverses and print the binary search tree
void bstree_traverse(BStree bst)
{
    bstree_traverse_helper(*bst);
}

// helper function for freeing the memory allocated for the binary search tree
void bstree_free_helper(BStree_node* root)
{
    if (root != NULL)
    {
        bstree_free_helper(root->left);
        bstree_free_helper(root->right);
        key_free(root->key);
        data_free(root->data);
        free(root);
    }
}

// frees the memory allocated for the binary search tree
void bstree_free(BStree bst)
{
    bstree_free_helper(*bst);
    free(bst);
}


