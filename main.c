#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

#define combs 256

typedef struct{
    int id;
    int count;
} letter;

typedef struct qnode{
    btnode *data;
    struct  qnode *next;
} qnode;

void qpush(qnode **head, btnode *data){
    qnode *tmp = (qnode*)malloc(sizeof(qnode));
    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void show_queue(qnode *node);

/** btnode pop(qnode **head){ */
/**     qnode *prev = NULL; */
/**     btnode data; */
/**     if (head == NULL){ */
/**         exit(-1); */
/**     } */
/**     prev = (*head); */
/**     data = prev->data; */
/**     (*head) = (*head)->next; */
/**     free(prev); */
/**     return data; */
/** } */

void delete_pqueue(qnode **head);

void print_table(letter* letters){
    puts("---------------------");
    puts("Character table");
    for(int i = 0; i < combs; i++){
        if(letters[i].count  > 0){
            printf("Number: %d\n", letters[i].id);
            printf("Character: %c\n", (char)letters[i].id);
            printf("Count: %d\n", letters[i].count);
            printf("\n");
        }
    }
    puts("-------------------");
}

int compar(const void* el1, const void* el2){
    letter f = *((letter*)el1);
    letter s = *((letter*)el2);

    if(f.count > s.count) return -1;
    if(f.count < s.count) return 1;
    return 0;
}

int main(int argc, char** argv){
    if(argc != 4){
        printf("Usage: huff ifile [-c|-x] ofile");
        return 0;
    }

    FILE* ifile = 0;
    ifile = fopen(argv[1], "r");

    letter letters[combs];
    for(int i = 0; i < combs; i++){
        letters[i].id = i;
        letters[i].count = 0;
    }

    // form table
    int c = 0;
    while(1){
        c = fgetc(ifile);
        if (c == EOF){
            break;
        }
        else{
            letters[c].count += 1;
        }
    }

    /** print_table(letters); */
    qsort(letters, combs, sizeof(letter), compar);
    /** print_table(letters); */

    //dirty fix
    int not_zero = -1;
    for(int i = 0; i < combs; i++){
        if(letters[i].count == 0){
            break;
        }
        else{
            not_zero++;
        }
    }
    printf("First not zero: %d\n", not_zero);

    qnode* head = NULL;
    /** qnode* tail = NULL; */

    for(int i = 0; i <= not_zero; i++){
        btnode *tmp = NULL;
        char txt[2] = {(char)letters[i].id, '\0'};
        insert_btnode(&tmp, txt, letters[i].count);
        qpush(&head, tmp);
    }

    qnode *iter = head;
    while(iter->next){
        print_btree(iter->data);
        iter = iter->next;
    }

    /** print_btree(tmp); */



    /** btnode *tree = NULL; */
    /** insert_btnode(tree); */

    fclose(ifile);
    return 0;
}
