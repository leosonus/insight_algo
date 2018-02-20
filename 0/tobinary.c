#include <stdio.h>
#define N 128

int a[N];

int main()
{
	int n, r, k, i;

	scanf("%d", &n);
	k = 0;

	while(n > 0) {
		r = n % 2;
		n = n / 2;
		a[k] = r;
		k++;
	}

	for(i=k-1; i>=0; i--)
		printf("%d", a[i]);

	printf("\n");
	return 0;
}
