#include <stdlib.h>

size_t myda_size(void* darray) {
    return *((size_t*)darray - 2);
}

