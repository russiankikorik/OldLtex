#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../my_darray/my_darray.h"
#include "phonebook.h"

void read_field(char* field) {
    int i;
    char buf;
    for (i = 0; i < STRSZ - 1; i++) {
        buf = fgetc(stdin);
        if (buf == '\n') { break; }
        field[i] = buf;
    }
    field[i] = '\0';
    if (buf != '\n') { while (fgetc(stdin) != '\n') {} }
}

void add_person(void** listptr) {
    void* list = *listptr;
    size_t oldSize = myda_size(list);
    list = myda_add(list);
    printf("print name, %d charachters max\n", STRSZ - 1);
    read_field(((Card*)list)[oldSize].name);
    printf("print surname, %d charachters max\n", STRSZ - 1);
    read_field(((Card*)list)[oldSize].surname);
    printf("print number, %d charachters max\n", STRSZ - 1);
    read_field(((Card*)list)[oldSize].number);
    *listptr = list;
}

void* find_person(void* uncasted_list) {
    Card* list = (Card*)uncasted_list;
    size_t size = myda_size(uncasted_list);
    size_t i;
    int selector;
    char buf[STRSZ];
    for (i = 0; i < STRSZ; i++) {
        buf[i] = 0;
    }
    printf("Search by:\n1. name\n2. surname\n3. number\n");
    scanf("%d", &selector);
    while (fgetc(stdin) != '\n') {}
    switch (selector) {
    case 1:
        printf("print name, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        for (i = 0; i < size; i++) {
            if (strcmp(list[i].name, buf) == 0) {
                return (void*)(list + i);
            }
        }
        printf("person not found\n");
        return NULL;
    case 2:
        printf("print surname, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        for (i = 0; i < size; i++) {
            if (strcmp(list[i].surname, buf) == 0) {
                return (void*)(list + i);
            }
        }
        printf("person not found\n");
        return NULL;
    case 3:
        printf("print number, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        for (i = 0; i < size; i++) {
            if (strcmp(list[i].number, buf) == 0) {
                return (void*)(list + i);
            }
        }
        printf("person not found\n");
        return NULL;
    default:
        printf("wrong value\n");
        return NULL;
    }
}

void edit_person(void* current) {
    size_t i;
    int selector;
    char buf[STRSZ];
    for (i = 0; i < STRSZ; i++) {
        buf[i] = 0;
    }
    printf("Edit:\n1. name\n2. surname\n3. number\n");
    scanf("%d", &selector);
    while (fgetc(stdin) != '\n') {}
    switch (selector) {
    case 1:
        printf("print name, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        strcpy(((Card*)current)->name, buf);
        return;
    case 2:
        printf("print surname, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        strcpy(((Card*)current)->surname, buf);
        return;
    case 3:
        printf("print number, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        strcpy(((Card*)current)->number, buf);
        return;
    default:
        printf("wrong value\n");
        return;
    }
}

void delete_person(void** listptr, void* current) {
    void* list = *listptr;
    list = myda_erase(list, current, NULL);
    *listptr = list;
}

void view_person(void* current) {
    printf("\n");
    fputs(((Card*)current)->name, stdout);
    printf("\n");
    fputs(((Card*)current)->surname, stdout);
    printf("\n");
    fputs(((Card*)current)->number, stdout);
    printf("\n\n");
}

void view_list(void* list) {
    size_t i;
    size_t size = myda_size(list);
    for (i = 0; i < size; i++) {
        view_person(myda_item(list, i));
    }
}

void demo_fill(void** listptr) {
    void* ls = *listptr;
    Card* list;
    ls = myda_resize(ls, 5, NULL);
    list = (Card*)ls;

    Card vasya = {
        .name = {'v', 'a', 's', 'y', 'a', '\0'},
        .surname = {'p', 'u', 'p', 'k', 'i', 'n', '\0'},
        .number = {'1', '1', '1', '1', '\0'}
        };
    *list = vasya;
    list++;
    Card petya = {
        .name = {'p', 'e', 't', 'y', 'a', '\0'},
        .surname = {'g', 'u', 'b', 'k', 'i', 'n', '\0'},
        .number = {'2', '2', '2', '2', '\0'}
        };
    *list = petya;
    list++;
    Card vova = {
        .name = {'v', 'o', 'v', 'a', '\0'},
        .surname = {'d', 'u', 'd', 'k', 'i', 'n', '\0'},
        .number = {'3', '3', '3', '3', '\0'}
        };
    *list = vova;
    list++;
    Card dima = {
        .name = {'d', 'i', 'm', 'a', '\0'},
        .surname = {'t', 'r', 'u', 'b', 'k', 'i', 'n', '\0'},
        .number = {'4', '4', '4', '4', '\0'}
        };
    *list = dima;
    list++;
    Card roma = {
        .name = {'r', 'o', 'm', 'a', '\0'},
        .surname = {'z', 'u', 'b', 'k', 'i', 'n', '\0'},
        .number = {'5', '5', '5', '5', '\0'}
        };
    *list = roma;
 

    *listptr = ls;
}

