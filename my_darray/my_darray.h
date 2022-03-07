#include <stddef.h>

#ifndef _MY_DARRAY_
#define _MY_DARRAY_

void* myda_create(size_t itemSize, size_t size);
/*
 * Creates an array of SIZE elements with items of size ITEMSIZE.
 * Returns pointer to the beginning of data.
 * Pointer preceded by two size_t elements containing SIZE and ITEMSIZE values.
*/
void myda_destroy(void* darray, void(*destroy)(void*));
/*
 * Destroy an array using function DESTROY for each element.
 * Pass NULL to DESTROY a if no function is necessary.
 * All values of the array must be initialized before using DESTROY.
 */
size_t myda_size(void* darray);
/* Returns size of an array. */
size_t myda_itemSize(void* darray);
/* Returns size of items in array. */
void* myda_resize(void* darray, size_t newSize, void(*destroy)(void*));
/*
 * Changes size of an array to NEWSIZE.
 * DESTROY can be specified, if size is reduced.
 * If DESTROY is not necessary, pass NULL.
 * Return pointer to new array. 
 */
void* myda_item(void* darray, size_t i);
/*
 * Returns pointer to item at index I.
 * If I is out of bonds returns NULL.
*/
void* myda_add(void* darray);
/*
 * Appends space for one item.
 * Returns pointer to new array.
*/
void* myda_insert(void* darray, size_t i);
/*
 * Inserts space for one item at index I.
 * If index is out of bonds, appends space to end of the array.
 * Returns pointer to new array.
*/
void* myda_remove(void* darray, size_t i, void(*destroy)(void*));
/*
 * Removes element at index I using DESTROY if it is not NULL.
 * If index is out of bonds the array is left unchanged and uncopied.
 * Returns pointer to new array.
*/
void* myda_erase(void* darray, void* item, void(destroy)(void*));
/*
 * Removes element at pointer ITEM using DESTROY if it is not NULL.
 * If ITEM out of bonds or not aligned the array is left unchanged and uncopied.
 * Returns pointer to new array.
*/
#endif

