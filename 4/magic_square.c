#include <stdio.h>

#define N 3

void print_sum()
{
    int i, j, k;

    for (i = 1; i <= N * N; i++)
        for (j = i + 1; j <= N * N; j++)
            for (k = j + 1; k <= N * N; k++)
                if (i + j + k == 15)
                    printf("%d %d %d\n", i, j, k);
}

void print_square(int arr[])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%d ", arr[i * N + j]);
        printf("\n");
    }
    printf("\n");
}

int is_magic_square(int arr[])
{
    int i, j;
    int sum;
    int s = 0;

    for (i = 0; i < N; i++)
        s += arr[i];

    for (i = N; i < N * N; i += N) {
        sum = 0;
        for (j = 0; j < N; j++)
            sum += arr[i + j];
        if (s != sum) {
            return 0;
        }
    }

    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N * N; j += N)
            sum += arr[i + j];
        if (s != sum) {
            return 0;
        }
    }

    sum = 0;
    for (i = 0; i < N * N; i += N + 1)
        sum += arr[i];
    if (s != sum) {
        return 0;
    }

    sum = 0;
    for (i = N - 1; i < N * N - 1; i += N - 1) {
        sum += arr[i];
    }
    if (s != sum) {
        return 0;
    }

    return 1;
}

void swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

void perm(int arr[], int l, int n, int k)
{
    int i;

    if (l == k) {
        if (is_magic_square(arr))
            print_square(arr);
        return;
    }

    for (i = l; i < n; i++) {
        swap(&arr[i], &arr[l]);
        perm(arr, l + 1, n, k);
        swap(&arr[i], &arr[l]);
    }
}

void find_magic_square()
{
    int arr[N * N];

    int i;
    for (i = 0; i < N * N; i++)
        arr[i] = i + 1;

    /*
    arr[0] = 6;
    arr[1] = 1;
    arr[2] = 8;
    arr[3] = 7;
    arr[4] = 5;
    arr[5] = 3;
    arr[6] = 2;
    arr[7] = 9;
    arr[8] = 4;

    printf("%d\n", is_magic_square(arr));
    */

    perm(arr, 0, N * N, N * N);
}

int main()
{
//    print_sum();
    find_magic_square();
    return 0;
}
