#include <stdio.h>
#include <stdlib.h>

// copied
double rand_real(double a, double b)
{
    return a + (b - a) * ((double) rand() / RAND_MAX);
}

double partition_expectation(int n, double lb, double ub)
{
    int in = 0, i;
    double p;

    for (i = 0; i < n; i++) {
        p = rand_real(0.0, 1.0);
        if (lb <= p && p <= ub)
            in++;
    }
    return (double) in / n;
}

int comp_double(const void *a, const void *b)
{
    double r = *((double *) a) - *((double *) b);

    if (r > 0)
        return 1;
    if (r < 0)
        return -1;
    return 0;
}

#define N 3

double median_partition_expectation(int n, double lb, double ub)
{
    int in = 0, i, j;
    double p[N];

    for (i = 0; i < n; i++) {
        for (j = 0; j < N; j++)
            p[j] = rand_real(0.0, 1.0);
        qsort(p, N, sizeof(double), comp_double);
        if (lb <= p[N / 2] && p[N / 2] <= ub)
            in++;
    }
    return (double) in / n;
}

int main()
{
    printf("%lf\n", median_partition_expectation(10000000, 0.1, 0.9));
    return 1;
}
