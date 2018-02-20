#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rand_real(double a, double b)
{
    return a + (b - a) * ((double) rand() / RAND_MAX);
}

int main()
{
    double x, y, e;
    int in = 0, i, n;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        x = rand_real(1, 2);
        y = rand_real(0, 1);
        if (x * y <= 1)
            in++;

		if ((i + 1) % (n/100) == 0) {
			e = pow(2, (double) (i + 1)  / in);
			printf("%d %lf\n", i + 1, e);
		}
    }
    e = pow(2, (double) n / in);
    printf("%lf\n", e);
    
    return 1;
}
