#include <stdlib.h>

void* myda_create(size_t itemSize, size_t size) {
    void* ptr = malloc(2 * sizeof(size_t) + itemSize*size);
    *((size_t*)ptr) = size;
    *((size_t*)ptr + 1) = itemSize;
    ptr = (void*)((size_t*)ptr + 2);
    return ptr;
}
