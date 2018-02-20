#include <stdio.h>
#include <stdlib.h>

int compare_called = 0;

typedef struct {
    int weight;
} record_t;

typedef struct {
    int maxi;
    int mini;
} result_t;

int compare_record(record_t a, record_t b)
{
    compare_called++;
    return a.weight - b.weight;
}

result_t find_max_min(record_t records[], int n)
{
    int maxi = 0, mini = 0, i;

    for (i = 1; i < n; i++)
        if (compare_record(records[i], records[maxi]) > 0)
            maxi = i;
    for (i = 1; i < n; i++) {
        if (i == maxi)
            continue;
        if (compare_record(records[i], records[mini]) < 0)
            mini = i;
    }
    return (result_t) {maxi, mini};
}

result_t find_max_min2(record_t records[], int n)
{
    int maxi, mini, big, small, i;

    if (compare_record(records[0], records[1]) > 0) {
        maxi = 0;
        mini = 1;
    } else {
        maxi = 1;
        mini = 0;
    }
    for (i = 2; i < n; i += 2) {
        if (compare_record(records[i], records[i + 1]) > 0) {
            big = i;
            small = i + 1;
        } else {
            big = i + 1;
            small = i;
        }
        if (compare_record(records[big], records[maxi]) > 0)
            maxi = big;
        if (compare_record(records[small], records[mini]) < 0)
            mini = small;
    }
    return (result_t) {maxi, mini};
}

#define NUM_RECORD 10000
#define WEIGHT_MAX 100000

void initialize_records(record_t records[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        records[i].weight = rand() % WEIGHT_MAX;
}

int main()
{
    record_t records[NUM_RECORD];
    result_t result;
    int i;

    initialize_records(records, NUM_RECORD);
    result = find_max_min2(records, NUM_RECORD);
    printf("min: %d  max: %d  compare_record() called %d times\n", result.mini, result.maxi, compare_called);
    printf("%d %d\n", records[result.mini].weight, records[result.maxi].weight);

    /* test */
    for (i = 0; i < NUM_RECORD; i++) {
        if (compare_record(records[i], records[result.maxi]) > 0) {
            printf("incorrect max index\n");
            break;
        }
        if (compare_record(records[i], records[result.mini]) < 0) {
            printf("incorrect min index\n");
            break;
        }
    }
    return 0;
}
