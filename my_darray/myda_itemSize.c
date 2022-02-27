#include <stdlib.h>

size_t myda_itemSize(void* darray) {
    return *((size_t*)darray - 1);
}

