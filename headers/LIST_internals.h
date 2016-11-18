#ifndef LIST_INTERNALS_H
#define LIST_INTERNALS_H

#include <stdint.h>
#include "LIST_exports.h"

void add_beginning(list_t *list, int32_t val);
void add_end(list_t *list, int32_t val);

#endif /* LIST_INTERNALS_H */