#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rand_real(double a, double b)
{
    return a + (b - a) * ((double) rand() / RAND_MAX);
}

double line_line_picking(int n)
{
    double total = 0, x, y;
    int i;

    for (i = 0; i < n; i++) {
        x = rand_real(0.0, 1.0);
        y = rand_real(0.0, 1.0);
        total += fabs(x - y);
    }
    return total / n;
}

double square_line_picking(int n)
{
    double total = 0, x1, x2, y1, y2;
    int i;

    for (i = 0; i < n; i++) {
        x1 = rand_real(0.0, 1.0);
        x2 = rand_real(0.0, 1.0);
        y1 = rand_real(0.0, 1.0);
        y2 = rand_real(0.0, 1.0);
        total += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    return total / n;
}

int main()
{
    printf("%lf\n", line_line_picking(10000000));
    printf("%lf\n", square_line_picking(10000000));

    return 1;
}
