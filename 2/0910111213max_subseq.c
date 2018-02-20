#include <stdio.h>
#include <stdlib.h>

#define N 100000

int max_consecutive_sum(int s[], int n)
{
    int i, j, k, sum, max_sum = s[0];

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            sum = 0;
            for (k = i; k <= j; k++)
                sum += s[k];
            if (sum > max_sum)
                max_sum = sum;
        }
    }
    return max_sum;
}

int max_consecutive_sum2(int s[], int n)
{
    int i, j, sum, max_sum = s[0];

    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = i; j < n; j++) {
            sum += s[j];
            if (sum > max_sum)
                max_sum = sum;
        }
    }
    return max_sum;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int max_sum2(int s[], int n)
{
    if (n == 1)
        return s[0];
    return max(max_sum2(s, n - 1) + s[n - 1], s[n - 1]);
}

int max_sum1(int s[], int n)
{
    if (n == 1)
        return s[0];
    return max(max_sum2(s, n), max_sum1(s, n - 1));
}

#if 1
int c[N];

void calculate_max_consecutive_sum(int s[], int n)
{
    int i;

    c[0] = s[0];
    for (i = 1; i < n; i++)
        c[i] = max(s[i], s[i] + c[i - 1]);
}
#endif

#if 1
int find_max_consecutive_sum(int s[], int n)
{
    if (n == 1)
        return s[0];
    return max(c[n - 1], find_max_consecutive_sum(s, n - 1));
}
#endif

#if 1
int find_max_consecutive_sum2(int s[], int n)
{
    int max_sum, i;

    max_sum = 0;
    for (i = 0; i < n; i++)
        if (c[i] > max_sum)
            max_sum = c[i];
    return max_sum;
}
#endif

int main()
{
    int s[N], i;

    for (i = 0; i < N; i++)
        s[i] = rand() % 201 - 100;


//    printf("%d\n", max_consecutive_sum2(s, N));
#if 0
    printf("%d\n", max_sum1(s, N));
#endif
    calculate_max_consecutive_sum(s, N);
    printf("%d\n", find_max_consecutive_sum(s, N));

    return 0;
}
