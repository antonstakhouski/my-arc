#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bin_tree{
    char str[257];
    int count;
    struct bin_tree* right, *left;
} btnode;

void insert_btnode(btnode** tree, char *str, int count);
void print_btree(btnode* tree);
void del_btree(btnode* tree);
