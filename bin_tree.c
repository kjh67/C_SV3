#include <stdlib.h>
#include <stdio.h>


typedef struct bintree *Bintree;

struct bintree {
    int data;
    Bintree left;
    Bintree right;
};

Bintree heapify(int* nums, Bintree tree) {
    // insert the first number
    // on each subsequent insertion, propogate the biggest item to the top
}

int main(void) {
    Bintree t = malloc(sizeof(struct bintree));
    int nums[] = {1,2,3,4,5};
}

