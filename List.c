#include "List.h"

void main(void)
{
    // Initiate the list 
    list_t *list = init();

    int i;

    for (i = 1; i <= 10; ++i)
    {
        add_node(list, i, get_last(list));
    }

    node_t *curr = get_first(list);

    for (i = 1; i < 4; ++i)
    {
        curr = get_next(curr);
    }

    remove_node(list, curr);

    //destroy(list);

    // And print it
    print_list(list);

    printf("%d\n", get_sum(list));
}

int32_t get_sum(list_t *list)
{
    return list->sum;
}

void destroy(list_t *list)
{
    node_t *curr_node = get_first(list);
    while(get_next(curr_node) != NULL)
    {
        curr_node = get_next(curr_node);
        free(get_previous(curr_node));
    }

    free(list);
}

node_t *get_next(node_t *node)
{
    return node->next;
}

node_t *get_previous(node_t *node)
{
    return node->previous;
}

uint32_t get_length(list_t *list)
{
    return list->length;
}

node_t *get_first(list_t *list)
{
    return list->first;
}

node_t *get_last(list_t *list)
{
    return list->last;
}

int32_t remove_node(list_t *list, node_t *node)
{
    int32_t value = node->value;

    if(list->first == node)
    {
        node_t *next_node = node->next;
        free(node);

        list->first = next_node;
        next_node->previous = NULL;

    }
    else if(list->last == node)
    {
        node_t *previous_node = node->previous;

        previous_node->next = NULL;
        list->last = previous_node;
    } 
    else
    {
        node_t *previous_node = node->previous;
        node_t *next_node = node->next;
        free(node);

        next_node->previous = previous_node;
        previous_node->next = next_node;
    }

    list->length--;
    list->sum -= value;
}

void add_node(list_t *list, int32_t val, node_t *node)
{
    // If the given node is the last node
    if (list->last == node) 
    {
        add_end(list, val);
    }
    else if (node == NULL)
    {  
        add_beginning(list, val);
    }
    else // Add the node between two existing nodes
    {
        node_t *new_node = (node_t *)ec_malloc(sizeof(node_t));
        new_node->value = val;
        new_node->previous = node;
        new_node->next = node->next;
        node->next = new_node;
        list->length++;
        list->sum += val;
    }
}

void add_end(list_t *list, int32_t val)
{
    // If it's the first node
    if (list->first == NULL)
    {
        add_beginning(list, val);
    }
    else
    {
        node_t *new_node = (node_t *)ec_malloc(sizeof(node_t));
        new_node->value = val;
        new_node->previous = list->last;
        new_node->next = NULL;
        list->last->next = new_node;
        list->last = new_node;
        list->length++;
        list->sum += val;
    }
}

void add_beginning(list_t *list, int32_t val)
{
    node_t *first_node = list->first;
    node_t *new_node = (node_t *)ec_malloc(sizeof(node_t));
    new_node->value = val;
    new_node->previous = NULL;

    // If it's not the first node in the list
    if (first_node != NULL)
    {
        list->first = new_node;
        new_node->next = first_node;
        first_node->previous = new_node;
        list->length++;
        list->sum += val;
    } 
    else
    {
        new_node->next = NULL;
        list->first = new_node;
        list->last = new_node;
        list->length++;
        list->sum += val;
    }
}

void print_list(list_t *list)
{
    node_t *current = get_first(list);
    while (current != NULL)
    {
        printf("%d -> ", get_value(current));
        current = get_next(current);
    }
    printf("\n");
}

int32_t get_value(node_t *node)
{
    return node->value;
}

// Allocationg and initiate a new list and returns a list pointer.
list_t *init()
{
    list_t *list = (list_t *)ec_malloc(sizeof(list_t));
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    list->sum = 0;
}

// Error Check malloc, gets size and return the pointer.
// If there is a problem it calls error() 
void *ec_malloc(uint16_t size)
{
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
    {
        error("in ec_malloc() on memory allocation.");
    }

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