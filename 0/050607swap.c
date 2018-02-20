//#include <stdio.h>

void wrong_swap(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

#if 0
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
#endif

void swap_arr(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main()
{
	int x = 1, y = 2;
	wrong_swap(x, y);
	printf("%d %d\n", x, y);
	return 0;
}
