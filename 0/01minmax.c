#include <stdio.h>

int min(int x, int y)
{
	if (x < y) {
		return x;
	}
	return y;
}

int max(int x, int y)
{
	if (x > y) {
		return x;
	}
	return y;
}

int max_arr(int arr[], int arr_len)
{
	int maxa, i;
	maxa = arr[0];
	for (i = 1; i < arr_len; i++)
		if (arr[i] > maxa)
			maxa = arr[i];

	return maxa;
}

int main()
{
	printf("%d\n", max(-5, -10));
	return 0;
}
