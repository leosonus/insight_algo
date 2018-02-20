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
    int i;

    count_car_change = count_car_not_change = 0;

    for (i = 0; i < NUM_TRIAL; i++) {
        choice = rand_int(NUM_DOOR);
        car = rand_int(NUM_DOOR);

        do {
            open = rand_int(NUM_DOOR);
        } while (open == choice || open == car);
        do {
            change = rand_int(NUM_DOOR);
        } while (change == choice || change == open);

        if (choice == car)
            count_car_not_change++;
        if (change == car)
            count_car_change++;
    }
    printf("%d %d\n", count_car_not_change, count_car_change);

    return 1;
}
