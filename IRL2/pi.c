#include <stdio.h>
#include <omp.h>

double step;
static long num_steps = 100000000L;

int main() {
    double pi = 0.0;
    step = 1.0 / (double)num_steps; // step number of very small bars!
    double T1, T2;

    T1 = omp_get_wtime();

    #pragma omp parallel default(none) shared(num_steps, step) reduction(+:pi)
    {
        double x=0; 
    
        #pragma omp for
        for (long i = 0; i < num_steps; i++) {
            x = (i + 0.5) * step;
            pi += (4.0 / (1 + x * x)) * step;
        }
    }

    T2 = omp_get_wtime();

    printf("Time: %lf, pi: %lf\n", T2 - T1, pi);
    return 0;
}
