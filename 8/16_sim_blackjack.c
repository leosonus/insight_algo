#include <stdio.h>
#include <stdlib.h>

#define NO_TRIAL 10000000

int sim(d)
{
    int total = d, r;

    while (total < 17) {
        r = rand() % 13 + 1;
        if (r > 10)
            r = 10;
        if (r == 1)
            r = 11;
        total += r;
    }
    if (total > 21)
        return 22;
    return total;
}

int main()
{
    int freq[23] = {0, }, d, i;
    
    scanf("%d", &d);
    for (i = 0; i < NO_TRIAL; i++)
        freq[sim(d)] += 1;
    for (i = 17; i <= 21; i++)
        printf("%d: %d\n", i, freq[i]);
    printf("bust: %d\n", freq[22]);

    return 1;
}
