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

matrix_t matrix_sum(matrix_t x, matrix_t y)
{
    matrix_t r;
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            r.e[i][j] = x.e[i][j] + y.e[i][j];
    return r;
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

int main()
{
    matrix_t x, y;

    printf("input X: ");
    x = input_matrix();
    printf("input Y: ");
    y = input_matrix();

    printf("X+Y:\n");
    print_matrix(matrix_sum(x, y));
    printf("X*Y:\n");
    print_matrix(matrix_prod(x, y));

    return 1;
}
