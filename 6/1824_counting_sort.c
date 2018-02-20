#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCORE   1000
#define NAME_LEN    20

typedef struct {
    int score;
    char name[NAME_LEN];
} record_t;

int comp(const void *a, const void *b)
{
    return ((record_t *) a)->score - ((record_t *) b)->score;
}

void counting_sort(record_t records[], int n)
{
    int count[MAX_SCORE + 1], i;
    record_t *sorted;
	
	sorted = (record_t *) malloc(sizeof(record_t) * n);
    for (i = 0; i < MAX_SCORE + 1; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[records[i].score]++;
    for (i = 1; i <= MAX_SCORE + 1; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        sorted[count[records[i].score] - 1] = records[i];
        count[records[i].score]--;
    }

    for (i = 0; i < n; i++)
        records[i] = sorted[i];
    free(sorted);
}

typedef struct node_s node_t;
struct node_s {
    char name[NAME_LEN];
    node_t *next;
};

void bucket_sort(record_t records[], int n)
{
    node_t *head[MAX_SCORE + 1], *tail[MAX_SCORE + 1], *new_node, *node, *prev;
    int score, i, t;

    for (i = 0; i < MAX_SCORE + 1; i++) {
        head[i] = NULL;
        tail[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        new_node = (node_t *) malloc(sizeof(node_t));

        strcpy(new_node->name, records[i].name);
        new_node->next = NULL;

        score = records[i].score;

        if (head[score] == NULL) {
            head[score] = new_node;
            tail[score] = new_node;
        } else {
            tail[score]->next = new_node;
            tail[score] = new_node;
        }
    }

    t = 0;
    for (i = 0; i <= MAX_SCORE; i++) {
        node = head[i];
        while (node != NULL) {
            records[t].score = i;
            strcpy(records[t].name, node->name);
            t++;
            prev = node;
            node = node->next;
            free(prev);
        }
    }
}

int main()
{
    record_t *records;
    int n, i;

    printf("input n: ");
    scanf("%d", &n);
    records = (record_t *) malloc(sizeof(record_t) * n);

    printf("input scores: ");
    for (i = 0; i < n; i++)
        scanf("%s %d", records[i].name, &(records[i].score));

    //qsort(records, n, sizeof(record_t), comp);
    //counting_sort(records, n);
    bucket_sort(records, n);

    printf("output:\n");
#if 0
    for (i = 0; i < n; i++)
        printf("%s %d\n", records[i].name, records[i].score);
#endif
    free(records);
    return 0;
}
