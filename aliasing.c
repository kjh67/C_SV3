#include <stdlib.h>
#include <stdio.h>

// struct number {
//     union data {
//         struct b32 {long int *int32; float *float32;} b32;
//         struct b64 {long long int *int64; double *double64;} b64;
//     } data;  
// };

// typedef struct number* Number;


struct test {
    // union data {
    //     short int p;
    //     long int q;
    //     char r;
    // } data;
    char name;
    char name2;
    long int number;
};
typedef struct test *Test;


int main(void) {
    // Number num32 = malloc(sizeof(struct number));
    // // float field will point to same memory as int field
    // *(num32->data.b32.int32) = 0;
    // num32->data.b32.float32 = num32->data.b32.int32;

    // Number num64 = malloc(sizeof(struct number));
    // *(num64->data.b64.int64) = 0;
    // num64->data.b64.double64 = num64->data.b64.int64;

    // printf("here");
    // fflush(stdout);
    // // set value of float, then retrieve int
    // *(num32->data.b32.float32) = 12.75;
    // long int test = *(num32->data.b32.int32);
    // printf("%ld\n", test);

    Test t1 = malloc(sizeof(struct test));
    Test t2 = malloc(sizeof(struct test));
    Test t3 = malloc(sizeof(struct test));

    // t1->data.p = 65;
    t1->name = 'p';
    t1->number = 2;
    // t2->data.q = 65;
    t2->name = 'q';
    t2->number = 2;
    // t3->data.r = 65;
    t3->name = 'r';
    t3->number = 2;

    printf("t1 at %p, name at %p, n2 at %p, number at %p\n", t1, &(t1->name), &(t1->name2), &(t1->number));
    printf("t2 at %p, name at %p, n2 at %p, number at %p\n", t2, &(t2->name), &(t2->name2), &(t2->number));
    printf("t3 at %p, name at %p, n2 at %p, number at %p\n", t3, &(t3->name), &(t3->name2), &(t3->number));
    printf("long int: %ld, char: %ld, struct: %ld\n", sizeof(long int), sizeof(char), sizeof(struct test));
}