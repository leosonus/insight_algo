/* From YH book p187 */

#include <stdio.h>

#define MAX_BEAD    1000
#define MAX_WT      5000
#define MIN_WT      1000

#define HEAVY   0
#define LIGHT 1
#define UNKNOWN 2

int bead[MAX_BEAD];
int normal, wrong;
int compare = 0, borrow = 0, btype;

void initialize(int size, int type)
{
    int i, wt;

    btype = type;
    srand(time(0));

    normal = rand() % (MAX_WT - MIN_WT) + MIN_WT;
    wrong = rand() % size;

    switch(type) {
        case HEAVY:
            wt = 1;
            break;
        case LIGHT:
            wt = -1;
            break;
        case UNKNOWN:
            if (rand() % 2 == 0)
                wt = -1;
            else 
                wt = 1;
            break;

    }

    for(i = 0; i < size; i++) {
        if (i != wrong) bead[i] = normal;
        else bead[i] = normal + wt;
    }
}

void print_result(int num)
{
    if (num == wrong) {
        switch(btype) {
            case HEAVY:
                printf("Heavy Type\n");
                break;
            case LIGHT:
                printf("Light Type\n");
                break;
            case UNKNOWN:
                printf("Unknown Type\n");
                break;
        }
        printf("# of bead: %d\n", num + 1);
        printf("# of comparison: %d\n", compare);
        if (borrow != 0)
            printf("You borrow beads\n");
    } else
        printf("Wrong\n");
}

int comparator(int *index1, int *index2, int sz)
{
    int i;
    long left = 0, right = 0;
    compare++;
    for(i=0; i<sz; i++) {
        if (index1[i] != -1)
            left += bead[index1[i]];
        else
            left += normal;

        if (index2[i] != -1)
            right += bead[index2[i]];
        else
            right += normal;
        if (index1[i] == -1 || index2[i] == -1)
            borrow = 1;
    }

    return right - left;
}
