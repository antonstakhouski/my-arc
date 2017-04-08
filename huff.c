#include <stdio.h>
#include<stdlib.h>

#define combs 256

struct letter{
    int id;
    char ch;
    int count;
};

void print_table(struct letter* letters){
    puts("---------------------");
    puts("Character table");
    for(int i = 0; i < combs; i++){
        if(letters[i].count  > 0){
            printf("Number: %d\n", letters[i].id);
            printf("Character: %c\n", letters[i].ch);
            printf("Count: %d\n", letters[i].count);
            printf("\n");
        }
    }
    puts("-------------------");
}

int compar(const void* el1, const void* el2){
    struct letter f = *((struct letter*)el1);
    struct letter s = *((struct letter*)el2);

    if(f.count > s.count) return 1;
    if(f.count < s.count) return -1;
    return 0;
}

int main(int argc, char** argv){
    if(argc != 4){
        printf("Usage: huff ifile [-c|-x] ofile");
        return 0;
    }

    FILE* ifile = 0;
    ifile = fopen(argv[1], "r");

    struct letter letters[combs];
    for(int i = 0; i < combs; i++){
        letters[i].id = i;
        letters[i].ch = (char) i;
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

    print_table(letters);
    qsort(letters, combs, sizeof(struct letter), compar);
    print_table(letters);

    int not_zero = 0;
    for(int i = 0; i < combs; i++){
        if(letters[i].count != 0){
            not_zero = i;
            break;
        }
    }
    printf("First not zero: %d\n", not_zero);

    fclose(ifile);
    return 0;
}
