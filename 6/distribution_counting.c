#include <stdio.h>
#include <stdlib.h>

#define MAX_SCORE 1000

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

//--------------------------------------------- copied


int comp(const void *a, const void *b)
{
	return (*((int *) a) - *((int *)b));
}


void distribution_counting(int scores[], int n) 
{
    int count[MAX_SCORE + 1], t = 0, i, j;

    for (i = 0; i < MAX_SCORE + 1; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[scores[i]]++;

    for (i = 0; i <= MAX_SCORE; i++)
        for (j = 0; j < count[i]; j++) {
            scores[t] = i;
            t++;
        }
}


int main()
{
    int *scores, n, i;

    printf("input n: ");
    scanf("%d", &n);
    scores = (int *) malloc(sizeof(int) * n);

    printf("input scores: ");
    for (i = 0; i < n; i++)
        scanf("%d", &(scores[i]));
    //distribution_counting(scores, n);
#if 1
	//quicksort(scores, n);
	qsort(scores, n, sizeof(int), comp);
#endif
#if 0
    printf("output: ");
	print_arr(scores, n);
#endif
    free(scores);
    return 0;
}
