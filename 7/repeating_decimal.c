#include <stdio.h>
#define MAXN 10000

int decimal[MAXN], r[MAXN];

int main()
{
    int a, b, remain, n = 0, i, j;

    printf("input a, b: ");
    scanf("%d %d", &a, &b);
    printf("%d.", a/b);
    remain = a % b;
    while(1) {
        remain *= 10;
        for(i=0; i<n; i++)
            if(r[i] == remain) {
                for(j=0; j<i; j++)
                    printf("%d", decimal[j]);
                printf("(");
                for(j=i; j<n; j++)
                    printf("%d",decimal[j]);
                printf(")");
                return 1;
            }
        r[n] = remain;
        decimal[n] = remain/b;
        remain -= decimal[n] * b;
        n++;
    }
    return 0;
}
