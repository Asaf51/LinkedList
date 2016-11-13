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
void add_node(List *list, int val, Node *node);