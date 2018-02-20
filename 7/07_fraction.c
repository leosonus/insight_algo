#include <stdio.h>

int main()
{
    int a, b, c, d;

    printf("input a, b, c, d: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d/%d + %d/%d = %d/%d\n", a, b, c, d, a * d + b * c, b * d);
    printf("%d/%d - %d/%d = %d/%d\n", a, b, c, d, a * d - b * c, b * d);

    return 1;
}
