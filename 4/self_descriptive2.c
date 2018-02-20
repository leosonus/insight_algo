#include <stdio.h>

#define MAXN 20
#define min(x, y) (((x) < (y)) ? (x):(y))

static int count = 0;

void print_if_self_descriptive(int num[], int l)
{
    int i, j, c;
	count++;

    for (i = 0; i < l; i++) {
        c = 0;
        for (j = 0; j < l; j++)
            if (i == num[j])
                c++;
        if (c != num[i])
            return;
    }
    for (i = 0; i < l; i++)
        printf("%d", num[i]);
    printf("\n");
}

void self(int num[], int l, int n, int r)
{
    int i;

    if (r == 0) {
        print_if_self_descriptive(num, l);
        return;
    }

    for (i = 0; i < n; i++) {
        num[l] = i;
        self(num, l + 1, n, r - 1);
    }
}

void self2(int num[], int l, int n, int r)
{
    int i, t;

    if (r == 0) {
		print_if_self_descriptive(num, l);
		return;
	}

	t = 0;
	for (i = 0; i < l; i++)
		if (num[i] == l)
			t++;

    for (i = t; i < t + (n - l); i++) {
        num[l] = i;
        self2(num, l + 1, n, r - 1);
    }
}

void self3(int num[], int l, int n, int r, int s)
{
    int i, t;

    if (r == 0) {
		print_if_self_descriptive(num, l);
		return;
	}

	t = 0;
	for (i = 0; i < l; i++)
		if (num[i] == l)
			t++;

    for (i = t; i < min(t + (n - l), n - s + 1); i++) {
        num[l] = i;
        self3(num, l + 1, n, r - 1, s + i);
    }
}

void self_descriptive(int n) 
{
	int num[MAXN];
    //self(num, 0, 10, n);
    //self2(num, 0, 10, n);
    self3(num, 0, 10, n, 0);
}

int main()
{
    int n;

	scanf("%d", &n);
	self_descriptive(n);
	printf("count: %d\n", count);
    return 0;
}
