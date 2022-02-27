#include <stdlib.h>
#include "my_darray.h"

void* myda_insert(void* darray, size_t i) {
    size_t oldSize = myda_size(darray);
    size_t itemSize = myda_itemSize(darray);
    if (i >= oldSize) {return myda_add(darray);}
    void* new_darray = myda_create(itemSize, oldSize + 1);
    size_t j, k;
    for (j = 0; j < i; j++) {
	for (k = 0; k < itemSize; k++) {
	    ((char*)new_darray)[k + j * itemSize] =
		((char*)darray)[k + j * itemSize];
	}
    }
    for (; j < oldSize; j++) {
	for (k = 0; k < itemSize; k++) {
	    ((char*)new_darray)[k + (j+1) * itemSize] =
		((char*)darray)[k + j * itemSize];
	}
    }
    myda_destroy(darray, NULL);
    return new_darray;
}

