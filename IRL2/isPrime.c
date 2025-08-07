#include <stdio.h>
#include <omp.h>
#include <math.h>

int N = 50000000;

//If is prime, returns 1; else returns 0
int isPrime(int n) {
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++)
    {
        if(n % i == 0){
            return 0;
        } 
    }

    return 1;
}

int main()
{
    int countPrimes = 0;
    double begin,end;

    //Task: find the total number of prime numbers in the range [2, N]
    begin = omp_get_wtime();
    #pragma omp parallel for reduction(+:countPrimes)
    for (int i = 2; i < N; i++)
    {
        countPrimes += isPrime(i);
    }
    end = omp_get_wtime();
    printf("Found %d prime numbers between 1 and %d\n", countPrimes, N);
    printf("Took %lfs to find primes\n", end-begin);
}
