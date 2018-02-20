#include <stdio.h>
#include <stdlib.h>

// copied
double rand_real(double a, double b)
{
    return a + (b - a) * ((double) rand() / RAND_MAX);
}

double pi_expectation(int n)
{
    double x, y;
    int in = 0, i;

    for (i = 0; i < n; i++) {
        x = rand_real(-1, 1);
        y = rand_real(-1, 1);
        if (x * x + y * y <= 1)
            in++;
    }
    return (double) 4 *in / n;
}

int main() 
{
	int n;
    scanf("%d", &n);
    printf("%lf\n", pi_expectation(n));

    return 1;
}
