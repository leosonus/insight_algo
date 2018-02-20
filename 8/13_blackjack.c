#include <stdio.h>

#define P_10    (4.0/13.0)
#define P_OTHER (1.0/13.0)

double p_dealer(int d, int n)
{
    double r = 0;
    int i;

    if (n < d)
        return 0.0;
    if (n == d)
        return 1.0;
    if (n > d && d >= 17)
        return 0.0;

    for (i = 2; i <= 11; i++)
        r += p_dealer(d + i, n) * (i == 10 ? P_10 : P_OTHER);
#if 0
    r += P_OTHER * ((d > 10) ? p_dealer(d + 1, n) : p_dealer(d + 11, n));
#endif
    return r;
}

double bust(int d)
{
    double p = 1;
    int i;

    for (i = 17; i <= 21; i++)
        p -= p_dealer(d, i);
    return p;
}

int main()
{
    int i, d;

    printf("input dealer's open card: ");
    scanf("%d", &d);
    for (i = 17; i <= 21; i++)
        printf("%d: %.3lf\n", i, p_dealer(d, i));
    printf("bust: %.3lf\n", bust(d));

    return 1;
}
