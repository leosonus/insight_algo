#include <stdio.h>
#include <math.h>

double pi(int n, int up)
{
    double interval, x, y, s;
    int i;

    s = 0;
    interval = (double) 1 / (double) n;
    for (i = 0; i < n; i++) {
        x = interval * (double) (i + up);
        y = sqrt(1 - x * x);
        s += y;
    }

    return s * interval * (double) 4;
}

int main()
{
    int n;

    printf("input n: ");
    scanf("%d", &n);
    printf("%lf < pi < %lf\n", pi(n, 1), pi(n, 0));
    return 0;
}
