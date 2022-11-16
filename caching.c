#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int* initialise(int dasize) {
    int* adata = malloc(dasize*dasize*sizeof(int));
    for (int j=0; j!= dasize; j++) {
        for (int i=0; i!= dasize; i++) {
            adata[i + j*dasize] = i;
        }
    }
    return adata;
}


int dm_sumarray0(int dasize, int* adata) {
    int sum = 0; for (int i=0; i!=dasize; i++) {
        for (int j=0; j!=dasize; j++) {
            sum += adata[j + i*dasize];
        }
    }
    return sum;
}


int dm_sumarray1(int dasize, int* adata) {
    int sum = 0; for (int i=0; i!=dasize; i++) {
        for (int j=0; j!= dasize; j++) {
            sum += adata[i + j*dasize];
        }
    }
    return sum;
}


int dm_sumarray2(int dasize, int* adata) {
    int sum = 0; for (int j=0; j!=dasize; j++) {
        int i=0;
        while (i!=dasize) {
            int v = adata[i + j*dasize];
            sum += v;
            i = v+1;
        }
    }
    return sum;
}



int main(int argc, char* argv[]) {
    int size;
    if (argc == 2) {
        size = atoi(argv[1]);
    }
    else {size=100;}
    int* data = initialise(size);

    clock_t start;
    clock_t end;
    double diff;
    int sum = 0;
    
    // FIRST METHOD
    start = clock();
    sum = dm_sumarray0(size, data);
    end = clock();
    diff = (double) (end-start) / CLOCKS_PER_SEC;
    printf("Method 1: sum was %d, time was %lf\n", sum, diff);

    // SECOND METHOD
    start = clock();
    sum = dm_sumarray1(size, data);
    end = clock();
    diff = (double) (end-start) / CLOCKS_PER_SEC;
    printf("Method 2: sum was %d, time was %lf\n", sum, diff);

    // THIRD METHOD
    start = clock();
    sum = dm_sumarray2(size, data);
    end = clock();
    diff = (double) (end-start) / CLOCKS_PER_SEC;
    printf("Method 3: sum was %d, time was %lf\n", sum, diff);
}

