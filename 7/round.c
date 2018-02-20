#include <stdio.h>

int myround(double x)
{
    return (int) (x + 0.5);
}

int main()
{
    double x;
    scanf("%lf", &x);
    printf("%lf\n", myround(x));
    return 0;
}
