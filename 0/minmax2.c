#include <stdio.h>

#define max(x, y) (x)>(y)?(x):(y)
#define min(x, y) ((x)<(y)?(x):(y))

int max_arr2(int arr[], int arr_len)
{
	if (arr_len == 1)
		return arr[0];
	else
		return max(arr[arr_len - 1], max_arr2(arr, arr_len - 1));
}

int Max(int x, int y)
{
	if (x > y) {
		return x;
	}
	return y;
}

int main()
{
	printf("%d\n", 2 * max(2, 3));

	{
		int i, j;
		i = 4;
		j = max(3, i++);
		printf("%d %d\n", i, j);

		{
			int a[1000];
			int i;

			for (i = 0; i < 1000; i++)
				a[i] = 1000 - i;

			printf("%d\n", max_arr2(a, 1000));
		}
	}
	return 0;
}
