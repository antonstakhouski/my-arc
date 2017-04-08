struct bin_tree{
    int data;
    int count;
    struct bin_tree* right, *left;
};
typedef struct bin_tree node;

void insert(node** tree, int val){
    node* temp = NULL;
    if(!(*tree)){
        temp = (node*)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        temo->count = 1;
        *tree = temp;
        return;
    }

    if(val == (*tree)->data){
        (*tree)->count++;
    }
    else{
        if(val < (*tree)->data){
            insert(&(*tree)->left, val);
        }
        else{
            if(val > (*tree->data)){
                insert(&(*tree)->right, val);
            }
        }
    }
}

void print_preorder(node* tree){
    if(tree){
        print("%d\n", tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void deltree(node* tree){
    if(tree){
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}
