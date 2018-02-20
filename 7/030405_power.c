#include <stdio.h>

double power(double x, int n)
{
    double s = 1.0;
    int i;

    for (i = 0; i < n; i++)
        s *= x;
    return s;
}

double power2(double x, int n)
{
    double s;

    if (n == 0)
        return 1.0;
    if (n == 1)
        return x;
    if (n % 2 == 0) {
        s = power(x, n / 2);
        return s * s;
    }
    return power(x, n - 1) * x;
}

double power3(double x, int n)
{
    double s = 1.0;

    while (n > 0) {
        if (n % 2 == 1) {
            s *= x;
            if (n == 1)
                return s;
        }
        x *= x;
        n /= 2;
    }
    return s;
}

int main()
{
    double x;
    int n;

    //scanf("%lf %d", &x, &n);
    x = 1.00000001;
    n = 100000000;
    printf("%lf\n", power(x, n));

    return 1;
}
