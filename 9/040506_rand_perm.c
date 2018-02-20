#include <stdio.h>
#include <stdlib.h>

// copied
void swap_arr(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// copied
unsigned rand_int(int n)
{
    return rand() % n;
}

void rand_perm(int a[], int n)
{
    int p, i;

    for (i = 0; i < n; i++)
        a[i] = -1;
    for (i = 0; i < n; i++) {
        p = rand_int(n);
        while (a[p] != -1) {
            p = (p + 1) % n;
        }
        a[p] = i;
    }
}

void rand_perm2(int a[], int n)
{
    int p, i;

    for (i = 0; i < n; i++)
        a[i] = -1;
    for (i = 0; i < n; i++) {
        do {
            p = rand_int(n);
        } while (a[p] != -1);
        a[p] = i;
    }
}

void rand_perm3(int a[], int n)
{
    int i, p;

    for(i=0; i < n; i++)
        a[i] = i;
    for (i = 0; i < n - 1; i++) {
        p = rand_int(n - i);
        swap_arr(a, i, i+ p);
    }
}

void shuffle(int a[], int n)
{
    int i, p;

	for (i = 0; i < n - 1; i++) {
        p = rand_int(n - i);
        swap_arr(a, i, i+ p);
    }
}

int shuffle_test()
{
    int a[100], i;

    for (i = 0; i < 100; i++)
        a[i] = i;
    shuffle(a, 100);
    for (i = 0; i < 100; i++)
        printf("%d ", a[i]);
    return 1;
}

int main()
{
    int a[1000000], n, i, j;

    scanf("%d", &n);

    for(j=0; j<20; j++) { 
        rand_perm3(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }

    return 0;
}
