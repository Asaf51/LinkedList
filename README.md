# List

This is a library for linked list.

## How to use

Basic functions

### Main functions


You can initiate a new list:
```
list_t *list = list_init();
```

Add new node to the list:
```c
// add between 2 exsiting nodes
list->add_node(list, value, previous_node);

// add in the beginning
list->add_node(list, value, NULL);

// add in the end
list->add_node(list, value, get_last(list));
```

Remove a node from the list:
```
list->remove_node(list, the_node_to_remove);
```

Destroy the list:
```
list->destroy(list);
```

### More functions
```c
// returns the first node by a given list
get_first(list);

// returns the last node by a given list
get_last(list);

// returns the length of the list 
get_lenght(list);

// returns the previous node by a given node
get_previous(node);

// returns the next node by a given node
get_previous(node);

// get value of node
get_value(node);

// get sum of list
get_sum(list);

// print the list
print_list(list);
```