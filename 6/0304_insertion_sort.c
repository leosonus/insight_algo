#include <stdio.h>
#include <stdlib.h>

#define CHECK

void insert(int arr[], int last)
{
    int temp, i;

    temp = arr[last];
    for (i = last; i > 0 && arr[i - 1] > temp; i--)
        arr[i] = arr[i - 1];
    arr[i] = temp;
}

void insertion_sort(int arr[], int len)
{
    int i;

    for (i = 1; i < len; i++)
        insert(arr, i);
}

void insertion_sort2(int arr[], int n)
{
    int temp, i, l;

    for (l = 1; l < n; l++) {
        temp = arr[l];
        for (i = l; i > 0 && arr[i - 1] > temp; i--)
            arr[i] = arr[i - 1];
        arr[i] = temp;
    }
}

int check_sort(int sorted[], int unsorted[], int n)
{
    int exist[n], flag, i, j;

    for (i = 0; i < n - 1; i++)
        if (sorted[i] > sorted[i + 1])
            return 0;
    for (i = 0; i < n; i++)
        exist[i] = 0;
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < n; j++) {
            if (exist[j] == 0 && sorted[i] == unsorted[j]) {
                exist[j] = 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return 0;
    }
    return 1;
}


#define N_ELEMENTS 200

int main()
{
    int a[N_ELEMENTS];
#ifdef CHECK
    int b[N_ELEMENTS];
#endif
    int i;

    printf("Unsorted: ");
    for (i = 0; i < N_ELEMENTS; i++) {
        a[i] = random() % 10000;
#ifdef CHECK
        b[i] = a[i];
#endif
        printf("%d ", a[i]);
    }
    printf("\n");

    insertion_sort(a, N_ELEMENTS);
    printf("Sorted: ");
    for (i = 0; i < N_ELEMENTS; i++)
        printf("%d ", a[i]);
    printf("\n");
#ifdef CHECK
    printf("%d\n", check_sort(a, b, N_ELEMENTS));
#endif
    return 0;
}
