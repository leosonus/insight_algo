#include <stdio.h>

int main()
{
    int a, b, i;

    printf("input a,b: ");
    scanf("%d %d", &a, &b);
    i = 1;
    while (a > 0) {
        if (a * i >= b) {
            printf("1/%d ", i);
            a = a * i - b;
            b = b * i;
        }
        i++;
    }
    printf("\n");
    return 0;
}
