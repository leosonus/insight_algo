#include <stdio.h>
#define N 100

void print_decimal(int a, int b)
{
    int i;

    printf("%d.", a / b);
    for (i = 0; i < N; i++) {
        a %= b;
        a *= 10;
        printf("%d", a / b);
    }
    printf("\n");
}

void print_decimal2(int a, int b) 
{
    int decimal[N], remain[N];
    int i;

    printf("%d.", a / b);
    for (i = 0; i < N; i++) {
        a %= b;
        remain[i] = a;
        a *= 10;
        decimal[i] = a / b;
    }
    for (i = 0; i < N; i++)
        printf("%d", decimal[i]);
    printf("\n");
}

void print_decimal3(int a, int b) 
{
    int decimal[N], remain[N];
    int i, j, t;

    printf("%d.", a / b);
    for (i = 0; i < N; i++) {
        a %= b;
        for (j = 0; j < i; j++) {
            if (a == remain[j]) {
                for (t = 0; t < j; t++)
                    printf("%d", decimal[t]);
                printf("(");
                for (t = j; t < i; t++)
                    printf("%d", decimal[t]);
                printf(")");
                return;
            }
        }
        remain[i] = a;
        a *= 10;
        decimal[i] = a / b;
    }
}

int main()
{
    int a, b;

    printf("input a, b: ");
    scanf("%d %d", &a, &b);
    print_decimal3(a, b);

    return 1;
}
