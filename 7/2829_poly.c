#include <stdio.h>
#include <math.h>

#define MAXN 100

double calc_poly(double x, double a[], int n)
{
    double p = 0;
    int i;

    for (i = 0; i < n; i++)
        p += a[i] * pow(x, i);
    return p;
}

double calc_poly2(double x, double a[], int n)
{
    double p;
    int i;

    p = a[n];
    for (i = n - 1; i >= 0; i--)
        p = p * x + a[i];
    return p;
}

void print_poly(double a[], int n)
{
    int i;

    for (i = n - 1; i >= 1; i--)
        printf("%lfx^%d + ", a[i], i);
    printf("%lf\n", a[0]);
}

int main()
{
    double a[MAXN], k;
    int n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%lf", &a[i]);
    scanf("%lf", &k);

    print_poly(a, n);
    printf("%lf\n", calc_poly(k, a, n));
    return 0;
}
