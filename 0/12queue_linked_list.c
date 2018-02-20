#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int key;
    struct _node *next;
} node_t;

node_t *head = NULL, *tail = NULL;

void insert_node(int n)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
	//printf("[%p]\n", new_node);

    new_node->key = n;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int delete_node()
{
	node_t *node;

	if (head == NULL) {
		return -1;
	}
	
	node = head;
	head = head->next;
	if (head == NULL) {
		tail = NULL;
	}
	return node->key;
}

int main() 
{
	int n;

	do {
		printf("input number: ");
		scanf("%d", &n);

		if (n > 0) {
			insert_node(n);
		}
		else if (n == 0) {
			int r;
			r = delete_node();
			printf("[%d]\n", r);

		}
	} while (n >= 0);
	return 0;
}
