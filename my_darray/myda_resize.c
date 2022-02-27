#include <stdlib.h>
#include "my_darray.h"
void* myda_resize(void* darray, size_t newSize,  void(*destroy)(void*)) {
    size_t oldSize = myda_size(darray);
    size_t itemSize = myda_itemSize(darray);
    size_t sz = (oldSize < newSize) ? oldSize : newSize;
    size_t i;
    size_t j;
    void* new_darray = myda_create(itemSize, newSize);
    for (i = 0; i < sz; i++) {
	for (j = 0; j < itemSize; j++) {
	    ((char*)new_darray)[j + i * itemSize] = ((char*)darray)[j + i * itemSize];
	}
    }
    if (destroy != NULL) {
	for (; i < oldSize; i++) {
	    destroy((void*)((char*)darray+i*itemSize));
	}
    }
    myda_destroy(darray, NULL);
    return new_darray;
}

