#include <stdio.h>
#include <stdlib.h>

#define SLOT_SIZE 10

// copied
void print_arr(int arr[], int arr_len)
{
	int i;

	for (i = 0; i < arr_len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// copied
unsigned rand_int(int n)
{
    return rand() % n;
}

int slot[SLOT_SIZE];

void init_slot()
{
    int i;

    for (i = 0; i < SLOT_SIZE; i++)
        slot[i] = -1;
}

void golla(int i)
{
    static int packet_count = 0;
    slot[rand_int(SLOT_SIZE)] = i;
    packet_count++;
}

void golla2(int i)
{
    static int packet_count = 0;
    if (packet_count < SLOT_SIZE)
        slot[packet_count] = i;
    else {
        if ((rand_int(packet_count + 1)) < SLOT_SIZE)
            slot[rand_int(SLOT_SIZE)] = i;
    }
    packet_count++;
}

int main()
{
    int n, i;

    printf("input n: ");
    scanf("%d", &n);
    init_slot();
    for (i = 0; i < n; i++)
        golla(i);
    print_arr(slot, SLOT_SIZE);

    return 0;
}
