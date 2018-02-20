#include <stdio.h>
#include <stdlib.h>

#define NUM_DOOR  3
#define NUM_TRIAL 10000

int rand_int(int n)
{
    return rand() % n;
}

int main()
{
    int car, choice, open, change;
    int count_car_change, count_car_not_change;
    int open_ok, i;

    open_ok = 0;
    count_car_change = count_car_not_change = 0;

    for (i = 0; i < NUM_TRIAL; i++) {
        choice = rand_int(NUM_DOOR);
        car = rand_int(NUM_DOOR);

        do {
            open = rand_int(NUM_DOOR);
        } while (open == choice);
        if (open == car)
            continue;
        open_ok++;

        do {
            change = rand_int(NUM_DOOR);
        } while (change == choice || change == open);
        if (choice == car)
            count_car_not_change++;
        if (change == car)
            count_car_change++;
    }
    printf("%d %d %d\n", open_ok, count_car_not_change, count_car_change);

    return 1;
}
