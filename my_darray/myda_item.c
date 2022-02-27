#include <stdlib.h>

void* myda_item(void* darray, size_t i) {
    size_t size = *((size_t*)darray - 2);
    if (i >= size) {return NULL;};
    size_t itemSize = *((size_t*)darray - 1);
    return (void*)((char*)darray+i*itemSize);
}

