#include <stdio.h>
#include <stdlib.h>

#define NUM_TRIAL 10000
#define NUM_DOT   10000

#define L 10

double rand_real(double a, double b)
{
    return a + (b - a) * ((double) rand() / RAND_MAX);
}

double cover_area(int n)
{
    double x[n], y[n], px, py;
    int in = 0, i, j;

    for (i = 0; i < n; i++) {
        x[i] = rand_real(0, L);
        y[i] = rand_real(0, L);
    }
    for (i = 0; i < NUM_DOT; i++) {
        px = rand_real(0, L);
        py = rand_real(0, L);
        for (j = 0; j < n; j++)
            if ((x[j] - px) * (x[j] - px) + (y[j] - py) * (y[j] - py) <= 1) {
                in++;
                break;
            }
    }
    return (double) in / NUM_DOT * (L * L);
}

int main()
{
    double cover_sum = 0;
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < NUM_TRIAL; i++)
        cover_sum += cover_area(n);
    printf("%lf\n", cover_sum / NUM_TRIAL);
    return 1;
}
