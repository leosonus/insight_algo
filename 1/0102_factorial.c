#include <stdio.h>

int factorial(int n)
{
	int r, i;

	r = 1;
	for (i = 2; i <= n; i++)
		r *= i;
	return r;
}

int factorial2(int n)
{
	//return (n == 1) ? 1 : n * factorial2(n - 1);
	if (n == 1)
		return 1;
	else
		return n * factorial2(n - 1);
}

int main()
{
    int n;

    printf("input n: ");
    scanf("%d", &n);
    printf("%d\n", factorial2(n));
    return 0;
}
