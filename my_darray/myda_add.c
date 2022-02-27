#include <stdlib.h>
#include "my_darray.h"

void* myda_add(void* darray) {
    size_t oldSize = myda_size(darray);
    void* new_darray = myda_resize(darray, oldSize + 1, NULL);
    return new_darray;
}

