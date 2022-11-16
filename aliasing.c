#include <stdlib.h>
#include <stdio.h>

struct number {
    union data
    {
        struct b32 {long int *int32; float *float32;} b32;
        struct b64 {long long int *int64; double *double64;} b64;
    } data;  
};

typedef struct number* Number;


int main(void) {
    Number num32 = malloc(sizeof(struct number));
    // float field will point to same memory as int field
    *(num32->data.b32.int32) = 0;
    num32->data.b32.float32 = num32->data.b32.int32;

    Number num64 = malloc(sizeof(struct number));
    *(num64->data.b64.int64) = 0;
    num64->data.b64.double64 = num64->data.b64.int64;

    printf("here");
    fflush(stdout);
    // set value of float, then retrieve int
    *(num32->data.b32.float32) = 12.75;
    long int test = *(num32->data.b32.int32);
    printf("%ld\n", test);



    int msg;

    if (1<2) {
        char* msg;
        printf(msg);
    }
}