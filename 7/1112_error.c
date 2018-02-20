#include <stdio.h>

#define N 1000000

#if 0
int main()
{
    double sum = 0, a = 0.1;
    int i;
   
    for (i = 0; i < N; i++)
        sum += a;
    printf("%lf\n", sum);
    return 1;
}
#endif

#if 1
int main()
{
	double x, y;

	x = 1234.567;
	x += 45.67844;
	x += 0.0004;

	y = 45.67844;
	y += 0.0004;
	y += 1234.567;

	printf("%lf, %lf\n", x, y);
	printf("%d\n", x == y);

    return 1;
}
#endif
