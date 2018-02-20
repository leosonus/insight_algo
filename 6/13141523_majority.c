#include <stdio.h>
#include <stdlib.h>
#include "pbook_time.h"

#define N 1000000
#define NO_MAJORITY (-1)

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

// copy----------------------------------------
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
    p = partition5(arr, len);
    quicksort(arr, p);
    quicksort(arr + p + 1, len - p - 1);
}

void partial_quicksort(int arr[], int len, int i, int j)
{
    int p;

    if (len <= 1)
        return;
    p = partition5(arr, len);

    if (p < i)
        partial_quicksort(arr + p + 1, len - p - 1, i - p - 1, j - p - 1);
    else if (j < p)
        partial_quicksort(arr, p, i, j);
    else {
        partial_quicksort(arr, p, i, p - 1);
        partial_quicksort(arr + p + 1, len - p - 1, 0, j - p - 1);
    }
}
// copy -----------------------------

int majority(int arr[], int len)
{
    int i, j, count;

    for (i = 0; i < len; i++) {
        count = 0;
        for (j = 0; j < len; j++)
            if (arr[i] == arr[j])
                count++;
        if (count > len / 2)
            return arr[i];
    }
    return NO_MAJORITY;
}

int majority2(int arr[], int len)
{
    int i, count = 0;

	quicksort(arr, len);
    for (i = 0; i < len; i++)
        if (arr[i] == arr[len / 2])
            count++;
    if (count > len / 2)
        return arr[len / 2];
    return NO_MAJORITY;
}

int majority3(int arr[], int len)
{
    int i, count = 0;

    partial_quicksort(arr, len, len / 2, len / 2);
    for (i = 0; i < len; i++)
        if (arr[i] == arr[len / 2])
            count++;
    if (count > len / 2)
        return arr[len / 2];
    return NO_MAJORITY;
}

int rmajority(int arr[], int len)
{
    int arr2[len / 2], arr2_len, i, count;

#if 0
    printf("->");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
#endif

    if (len == 0)
        return NO_MAJORITY;
    if (len == 1)
        return arr[0];

    if (len % 2 == 1) {
        count = 0;
        for (i = 0; i < len; i++)
            if (arr[i] == arr[len - 1])
                count++;
        if (count > len / 2)
            return arr[len - 1];
        len--;
    }

    arr2_len = 0;
    for (i = 0; i < len; i += 2)
        if (arr[i] == arr[i + 1]) {
            arr2[arr2_len] = arr[i];
            arr2_len++;
        }
    return rmajority(arr2, arr2_len);
}

int majority4(int arr[], int len)
{
    int i, candidate, count = 0;

    candidate = rmajority(arr, len);
    for (i = 0; i < len; i++)
        if (arr[i] == candidate)
            count++;
    if (count > len / 2)
        return candidate;
    return NO_MAJORITY;
}

int main()
{
    //int num[N];
	int* num = (int *) malloc(sizeof(int) *N);
	int n, i, r;

    printf("input n: ");
//    scanf("%d", &n);
	n = N;
    for (i = 0; i < n; i++)
//		scanf("%d", &num[i]);
//		num[i] = i & 1;
		num[i] = rand() & 3;
 
	START_TIME;
    r = majority(num, n);
	END_TIME;
    if (r == NO_MAJORITY)
        printf("No majority element\n");
    else
        printf("Majority element is %d\n", r);
    return 0;
}
