#include <stdio.h>

#define N 2

typedef struct {
    double e[N][N];
} matrix_t;

void print_matrix(matrix_t x)
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%lf ", x.e[i][j]);
        printf("\n");
    }
}

matrix_t matrix_prod(matrix_t x, matrix_t y)
{
    matrix_t r;
    double s;
    int i, j, k;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            s = 0;
            for (k = 0; k < N; k++)
                s += x.e[i][k] * y.e[k][j];
            r.e[i][j] = s;
        }
    return r;
}

matrix_t input_matrix()
{
    matrix_t r;
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%lf", &(r.e[i][j]));
    return r;
}

matrix_t matrix_power(matrix_t x, int n)
{
    matrix_t r;
    int i, j;

    if (n == 0) {
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                r.e[i][j] = (i == j);
        return r;
    }

    if (n == 1)
        return x;

    if (n % 2 == 0) {
        r = matrix_power(x, n / 2);
        return matrix_prod(r, r);
    }

    r = matrix_power(x, n - 1);
    return matrix_prod(x, r);
}

int main()
{
    matrix_t x;
    int n;

    printf("input X: ");
    x = input_matrix();
    printf("input n: ");
    scanf("%d", &n);
    print_matrix(matrix_power(x, n));

    return 1;
}
