#include <stdio.h>
#include <stdlib.h>
#include "pbook_time.h"

// copied
void swap_arr(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// copied
void print_arr(int arr[], int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int partition(int arr[], int len)
{
    int arr2[len], arr2_len, p, i;

    arr2_len = 0;
    for (i = 1; i < len; i++)
        if (arr[i] < arr[0]) {
            arr2[arr2_len] = arr[i];
            arr2_len++;
        }

    p = arr2_len;

    for (i = 0; i < len; i++)
        if (arr[i] >= arr[0]) {
            arr2[arr2_len] = arr[i];
            arr2_len++;
        }

    for (i = 0; i < len; i++)
        arr[i] = arr2[i];
    return p;
}

int partition2(int arr[], int len)
{
    int p, i;

    p = 0;
    for (i = 1; i < len; i++)
        if (arr[i] < arr[0])
            swap_arr(arr, ++p, i);
    swap_arr(arr, 0, p);
    return p;
}

int partition3(int arr[], int len)
{
    int p, i;

    swap_arr(arr, 0, rand() % len);
    p = 0;
    for (i = 1; i < len; i++)
        if (arr[i] < arr[0])
            swap_arr(arr, ++p, i);
    swap_arr(arr, 0, p);
    return p;
}

int partition4(int arr[], int len)
{
    int p, q;

    p = partition3(arr, len);
    q = p;
    while (q < len - 1 && arr[q + 1] == arr[p])
        q++;
    p = (p + q) / 2;
    return p;
}

int partition5(int arr[], int len)
{
    int i, j, t;

    swap_arr(arr, 0, rand() % len);
    t = arr[0];

    i = 0;
    j = len;
    while (1) {
        do {
            i++;
        } while (i < len && arr[i] < t);

        do {
            j--;
        } while (arr[j] > t);

        if (i > j)
            break;
        swap_arr(arr, i, j);
    }
    swap_arr(arr, 0, j);
    return j;
}

void quicksort(int arr[], int len)
{
    int p;

    if (len <= 1)
        return;
    p = partition2(arr, len);
    quicksort(arr, p);
    quicksort(arr + p + 1, len - p - 1);
}

void partial_quicksort(int arr[], int len, int i, int j)
{
    int p;

    if (len <= 1)
        return;
    p = partition(arr, len);

    if (p < i)
        partial_quicksort(arr + p + 1, len - p - 1, i - p - 1, j - p - 1);
    else if (j < p)
        partial_quicksort(arr, p, i, j);
    else {
        partial_quicksort(arr, p, i, p - 1);
        partial_quicksort(arr + p + 1, len - p - 1, 0, j - p - 1);
    }
}

int selection(int arr[], int len, int k)
{
    partial_quicksort(arr, len, k - 1, k - 1);
    return arr[k - 1];
}

void increasing_array(int a[], int len)
{
    int i;

    for (i = 0; i < len; i++)
        a[i] = i;
}

void decreasing_array(int a[], int len)
{
    int i;

    for (i = len - 1; i >= 0; i--)
        a[i] = i;
}

void zero_array(int a[], int len)
{
    int i;

    for (i = 0; i < len; i++)
        a[i] = 0;
}

void random_array(int a[], int len)
{
    int i;

    for (i = 0; i < len; i++)
        a[i] = rand() % 10000;
}

#define N_ELEMENTS 100000

#if 1
int main()
{
	int a[N_ELEMENTS];

	//random_array(a, N_ELEMENTS);
	   increasing_array(a, N_ELEMENTS);
	//   decreasing_array(a, N_ELEMENTS);
	//zero_array(a, N_ELEMENTS);
	//    print_arr(a, N_ELEMENTS);
	/*
	   a[0] = 4;
	   a[1] = 6;
	   a[2] = 3;
	   a[3] = 5;
	   a[4] = 1;
	   a[5] = 0;
	   a[6] = 2;
	   a[7] = 7;
	 */
	//quicksort(a, 8);
	START_TIME;
	quicksort(a, N_ELEMENTS);
	END_TIME;

	//printf("%d\n", selection(a, 8, 3));

	  //print_arr(a, 8);
	  //print_arr(a, N_ELEMENTS);

	  return 0;
}
#endif

#if 0
/* partial test */
int main()
{
    int partial_sorted[N_ELEMENTS];
    int sorted[N_ELEMENTS];

    int i;

    int s, t;

    s = 20;
    t = 30;

    increasing_array(sorted, N_ELEMENTS);
    memcpy(partial_sorted, sorted, N_ELEMENTS * sizeof(int));

    quicksort(sorted, N_ELEMENTS);
    partial_quicksort(partial_sorted, N_ELEMENTS, s, t);

    for (i = s; i <= t; i++)
        if (sorted[i] != partial_sorted[i]) {
            printf("error\n");
            exit(0);
        }

    return 0;
}
#endif
