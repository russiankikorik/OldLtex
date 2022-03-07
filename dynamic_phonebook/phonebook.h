#ifndef _PHONEBOOK_
#define _PHONEOOK_
#define STRSZ 16

typedef struct {
    char name[STRSZ];
    char surname[STRSZ];
    char number[STRSZ];
} Card;

void read_field(char* field);
/* Reads string from stdin into FIELD. */

void add_person(void** listptr);
/*
 * Replaces *LISTPTR array for extended by one
 * and fills appended card using stdin.
*/
void* find_person(void* uncasted_list);
/* 
 * Searches person in UNCASTED_LIST 
 * by value obtained from stdin.
*/
void edit_person(void* current);
/*
 * Edits card at pointer CURRENT
 * using value from stdin.
*/
void delete_person(void** listptr, void* current);
/*
 * Replaces *LISTPTR array for reduced by one
 * erasing card at CURRENT.
*/
void view_person(void* current);
/* Prints *CURRENT card fields to stdin. */

void view_list(void* list);
/* Prints whole LIST to stdin. */

void demo_fill(void** listptr);
/* Fills list for demonstration. */
#endif
