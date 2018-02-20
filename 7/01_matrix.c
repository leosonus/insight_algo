#include <stdio.h>

typedef struct {
    double a, b, c, d;
} matrix_t;

void print_matrix(matrix_t x)
{
    printf("%lf %lf\n", x.a, x.b);
    printf("%lf %lf\n", x.c, x.d);
}

matrix_t matrix_sum(matrix_t x, matrix_t y)
{
    matrix_t r;

    r.a = x.a + y.a;
    r.b = x.b + y.b;
    r.c = x.c + y.c;
    r.d = x.d + y.d;
    return r;
}

matrix_t matrix_prod(matrix_t x, matrix_t y)
{
    matrix_t r;

    r.a = x.a * y.a + x.b * y.c;
    r.b = x.a * y.b + x.b * y.d;
    r.c = x.c * y.a + x.d * y.c;
    r.d = x.c * y.b + x.d * y.d;
    return r;
}

int main()
{
    matrix_t x, y;

    printf("input X: ");
    scanf("%lf %lf %lf %lf", &x.a, &x.b, &x.c, &x.d);
    printf("input Y: ");
    scanf("%lf %lf %lf %lf", &y.a, &y.b, &y.c, &y.d);

    printf("X+Y:\n");
    print_matrix(matrix_sum(x, y));
    printf("X*Y:\n");
    print_matrix(matrix_prod(x, y));

    return 1;
}
