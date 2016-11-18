#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/COMMON_exports.h"

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