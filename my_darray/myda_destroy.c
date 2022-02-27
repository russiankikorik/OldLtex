#include <stdlib.h>

void myda_destroy(void* darray, void(*destroy)(void*)) {
    size_t itemSize = *((size_t*)darray - 1);
    size_t size = *((size_t*)darray - 2);
    size_t i;
    if (destroy != NULL) {
	for (i = 0; i < size; i++) {
	    destroy((void*)((char*)darray+i*itemSize));
	}
    }
    free((size_t*)darray-2);
}
