#include <stdlib.h>
#include "my_darray.h"

void* myda_erase(void* darray, void* item, void(*destroy)(void*)) {
    size_t oldSize = myda_size(darray);
    size_t itemSize = myda_itemSize(darray);
    size_t lower = (size_t)darray;
    size_t upper = lower + (oldSize - 1) * itemSize;
    size_t it = (size_t)item;
    if (it < lower || upper < it) {
	return darray;
    }
    if (((it - lower) % itemSize) != 0) {
	return darray;
    }
    size_t i = (it - lower) / itemSize;
    void* new_darray = myda_create(itemSize, oldSize - 1);
    size_t j, k;
    for (j = 0; j < i; j++) {
	for (k = 0; k < itemSize; k++) {
	    ((char*)new_darray)[k + j * itemSize] =
		((char*)darray)[k + j * itemSize];
	}
    }
    for (; j < oldSize - 1; j++) {
	for (k = 0; k < itemSize; k++) {
	    ((char*)new_darray)[k + j * itemSize] =
		((char*)darray)[k + (j+1) * itemSize];
	}
    }
    if (destroy != NULL) {
	destroy(myda_item(darray, i));
    }
    myda_destroy(darray, NULL);
    return new_darray;
}

