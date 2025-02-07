#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    long num_steps = 1'000'000'000;
    double step;

    long i;
    double x, pi, sum = 0.0;

    double start, end, elapsed;

    // Get starting time
    start = omp_get_wtime();
    
    step = 1.0 / (double)num_steps;

    for (i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    
    pi = step * sum;

    // Get end time
    end = omp_get_wtime();

    // Calculate elapsed (it's in seconds)
    elapsed = end - start;

    printf("Integral value: %lf\n", pi);
    printf("Time taken: %lf s\n", elapsed);

    return 0;
}
