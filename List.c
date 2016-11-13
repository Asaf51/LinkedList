#include "List.h"

void main(void)
{
    // Initiate the list 
    List *list = init();
    
    // Add node at the beginning
    add_node(list, 5, NULL);

    // Add node at the end
    add_node(list, 7, list->last);

    // Print it
    print_list(list);
}

void add_node(List *list, int val, Node *node)
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
        Node *new_node = (Node *)ec_malloc(sizeof(Node));
        new_node->value = val;
        new_node->previous = node;
        new_node->next = node->next;
        node->next = new_node;
    }
}

void add_end(List *list, int val)
{
    // If it's the first node
    if (list->first == NULL)
    {
        add_beginning(list, val);
    }
    else
    {
        Node *new_node = (Node *)ec_malloc(sizeof(Node));
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
    Node *new_node = (Node *)ec_malloc(sizeof(Node));
    new_node->value = val;
    new_node->previous = NULL;

    // If it's not the first node in the list
    if (first_node != NULL)
    {
        list->first = new_node;
        new_node->next = first_node;
        first_node->previous = new_node;
    } 
    else
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