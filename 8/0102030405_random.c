#include <stdio.h>
#include <stdlib.h>

int rand_int(int n)
{
	return rand() % n;
}

int rand_int2(int n)
{
	//return rand() / (RAND_MAX / n + 1);
	return n * (rand() / (RAND_MAX + 1.0));
}

int rand_int3(int n)
{
	//unsigned int x = (RAND_MAX + 1u) / n;
	unsigned int y = (RAND_MAX + 1u) - RAND_MAX % n;
	unsigned int r;

	do {
		r = rand();
	} while (r >= y);

	return r % n; //  or r/x;
}

double rand_real(double a, double b)
{
    return a + (b - a) * ((double) rand() / RAND_MAX);
}

int weighted_rand_int(int n, int weight[], int total)
{
    int r, s = 0, i;

    r = rand() % total;
    for (i = 0; i < n; i++) {
        s += weight[i];
        if (s > r)
            break;
    }
    return i;
}

int weighted_rand_int2(int n, int cum_weight[], int total)
{
    int r, i;

    r = rand() % total;
    for (i = 0; i < n; i++)
        if (cum_weight[i] > r)
            break;
    return i;
}

int weighted_rand_int3(int map[], int total)
{
    int r;

    r = rand() % total;
    return map[r];
}

int main()
{
    int i;
    for(i=0; i<100000; i++)
        printf("%d\n", rand_int2(100));
    return 1;
}

#if 0

int main()
{
    int i;
#if 0
    for (i = 0; i < 1000; i++) {
        printf("%lf\n", rand_real(-0.5, 0.5));
    }
#endif
#if 1
    {
        int w[5] = {1, 4, 6, 4, 1};
        int cw[5] = {1, 5, 11, 15, 16};
        int map[16] = {0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4};

        for(i=0; i<100; i++) {
            unsigned u = weighted_rand_int(5, w, 16);
            //unsigned u = weighted_rand_int2(5, cw, 16);
            //unsigned u = weighted_rand_int3(map, 16);
            printf("%u ", u);
        }
        printf("\n");
    }
#endif
    return 1;
}
#endif
