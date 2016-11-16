#ifndef COMMON_EXPORTS_H
#define COMMON_EXPORTS_H

#include <stdint.h>

void *ec_malloc(uint16_t size);
void error(char *message);

#endif /* COMMON_EXPORTS_H */