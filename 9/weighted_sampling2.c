#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rand_real(double a, double b)
{
    return a + (b - a) * ((double) rand() / RAND_MAX);
}

double weighted_continuous()
{
    return sqrt(rand_real(0, 1));
}

#define NUM_TRIAL 1000000
#define N 100

int main()
{
    int count[N], i;

    for (i = 0; i < N; i++)
        count[i] = 0;

    for (i = 0; i < NUM_TRIAL; i++)
        count[(int) (weighted_continuous() * N)]++;

    for (i = 0; i < N; i++)
        printf("%lf %lf\n", (double) (i + 1) / N,
                (double) count[i] / NUM_TRIAL);
    return 0;
}
