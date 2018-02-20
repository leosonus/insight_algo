#include <stdio.h>

#define a_ELEMENTS 7

// copied
void swap_arr(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void stooge_sort(int arr[], int i, int j)
{
    int k;

    if (arr[i] > arr[j])
        swap_arr(arr, i, j);
    if (i + 1 >= j)
        return;
    k = (j - i + 1) / 3;
    stooge_sort(arr, i, j - k);
    stooge_sort(arr, i + k, j);
    stooge_sort(arr, i, j - k);
}

#define N_ELEMENTS 20

int main()
{
    int a[N_ELEMENTS], i;

    printf("Unsorted: ");
    for (i = 0; i < N_ELEMENTS; i++) {
        a[i] = random() % 10000;
        printf("%d ", a[i]);
    }
    printf("\n");

    stooge_sort(a, 0, N_ELEMENTS - 1);
    printf("Sorted: ");
    for (i = 0; i < N_ELEMENTS; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
