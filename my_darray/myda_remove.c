#include <stdlib.h>
#include "my_darray.h"

void* myda_remove(void* darray, size_t i, void(*destroy)(void*)) {
    size_t oldSize = myda_size(darray);
    if (i >= oldSize) {return darray;}
    size_t itemSize = myda_itemSize(darray);
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

