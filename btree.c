#include "btree.h"

void insert_btnode(btnode** tree, char* str, int count){
    btnode* temp = NULL;
    if(!(*tree)){
        temp = (btnode*)malloc(sizeof(btnode));
        temp->left = temp->right = NULL;
        strcpy(temp->str, str);
        temp->count = count;
        *tree = temp;
        return;
    }

    if(strcmp(str, (*tree)->str) < 0){
        insert_btnode(&(*tree)->left, str, count);
    }
    else{
        insert_btnode(&(*tree)->right, str, count);
    }
}

void print_btree(btnode* tree){
    if(tree){
        printf("String: ");
        puts(tree->str);
        printf("Count :%d\n\n", tree->count);
        print_btree(tree->left);
        print_btree(tree->right);
    }
}

void del_btree(btnode* tree){
    if(tree){
        del_btree(tree->left);
        del_btree(tree->right);
        free(tree);
    }
}
