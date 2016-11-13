#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct Node{
    struct Node *previous;
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *first;
    Node *last;
} List;

void *ec_malloc(uint16_t size);
void error(char *message);
List *init();
void print_list(List *list);
void add_beginning(List *list, int val);
void add_end(List *list, int val);

void main(void)
{
    List *list = init();
    add_beginning(list, 5);
    add_beginning(list, 7);
    add_beginning(list, 8);
    add_end(list, 10);
    print_list(list);
}

void add_end(List *list, int val)
{
    // If it's the first node
    if (list->first == NULL)
        add_beginning(list, val);
    else
    {
        Node *new_node = (Node *)ec_malloc(sizeof(List));
        new_node->value = val;
        new_node->previous = list->last;
        new_node->next = NULL;
        list->last->next = new_node;
        list->last = new_node;
    }
}

void add_beginning(List *list, int val)
{
    Node *first_node = list->first;
    Node *new_node = (Node *)ec_malloc(sizeof(List));
    new_node->value = val;
    new_node->previous = NULL;

    // If it's not the first node in the list
    if (first_node != NULL)
    {
        list->first = new_node;
        new_node->next = first_node;
        first_node->previous = new_node;
    } else
    {
        new_node->next = NULL;
        list->first = new_node;
        list->last = new_node;
    }
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

// Allocationg and initiate a new list and returns a list pointer.
List *init()
{
    List *list = (List *)ec_malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
}

// Error Check malloc, gets size and return the pointer.
// If there is a problem it calls error() 
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