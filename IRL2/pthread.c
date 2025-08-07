#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <pthread.h>

#define N 512*1024*1024
#define NUMOFTHREADS 8
#define SIZE N/NUMOFTHREADS

int *A, *B;

static void* start_routine(void* id){
    int offset = *(int *) id;
    long *dot_product = malloc(sizeof(long));
    *dot_product = 0;

    for (int i = offset * SIZE; i < (offset+1) * SIZE; i++)
    {
        *dot_product += A[i]*B[i];
    }
    
    free(id); 
    
    return dot_product;
}

int main () {
    long dot_product = 0;
    double begin,end; // Timestamps for beginning and end of computation
    void* return_value;

    pthread_t threads[NUMOFTHREADS];

    //Allocate Array A and B with N elements
    A = calloc(N, sizeof(int));
    B = calloc(N, sizeof(int));
    
    //Initialize arrays
    for (int i = 0; i < N; i++)
    {
        int n = rand() % 101;
        A[i] = n;
        B[i] = n;
    }
    
    //Now running time-stamp
    begin = omp_get_wtime();

    
    for (int i = 0; i < NUMOFTHREADS; i++)
    {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&threads[i], NULL, start_routine, (void *) thread_id);
    }

    for (int i = 0; i < NUMOFTHREADS; i++)
    {
        pthread_join(threads[i], &return_value);
        dot_product += *(long *) return_value;
        free(return_value);
    } 
    
    end = omp_get_wtime();

    printf("The final dotproduct is %ld\n", dot_product);
    printf("Time to execute was %lfs\n", end-begin);

    free(A);
    free(B);

    return 0;
}
