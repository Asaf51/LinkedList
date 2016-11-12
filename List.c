#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct Node{
	int value;
	struct Node *next;
	struct Node *previous;
} Node;

typedef struct {
	Node *first;
	Node *last;
} List;

void *ec_malloc(uint16_t size);
void error(char *message);
List *init();
void print_list(List *list);
void add_end(List list, int val);

int main()
{
	List *list = init();
	//add_end(list, 5);
	//add_end(list, 6);
	//add_end(list, 7);
	print_list(list);
}

void add_end(List list, int val)
{
	Node *last_node = list->last;
	Node* new_node = (Node *)ec_malloc(sizeof(Node));
	new_node->value = val;
	last_node->next = new_node;
	new_node->next = NULL;
	new_node->previous = last_node;
}

void print_list(List *list)
{
	Node *current = list->first;
	while (current != NULL)
	{
		printf("%d -> ", current->value);
		current = (Node *)current->next;
	}
}

List *init()
{
	List *list = (List *)ec_malloc(sizeof(List));
	list->first = NULL;
	list->last = NULL;
}

void *ec_malloc(uint16_t size)
{
	void *ptr;
	ptr = malloc(size);
	if (ptr == NULL)
		error("in ec_malloc() on memory allocation.");

	return ptr;

}

void error(char *message)
{
	char error_message[100];

	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 83);
	perror(error_message);
	exit(-1);
}