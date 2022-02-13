#include <stdio.h>
#include <stddef.h>
#include <string.h>
#define ARRSZ 10
#define STRSZ 16

typedef struct {
    char name[STRSZ];
    char surname[STRSZ];
    char number[STRSZ];
} Card;

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

void add_person(Card* list, size_t* szptr) {
    if (*szptr == ARRSZ) {
        printf("list is full\n");
        return;
    }
    printf("print name, %d charachters max\n", STRSZ - 1);
    read_field(list[*szptr].name);
    printf("print surname, %d charachters max\n", STRSZ - 1);
    read_field(list[*szptr].surname);
    printf("print number, %d charachters max\n", STRSZ - 1);
    read_field(list[*szptr].number);
    *szptr += 1;
}

Card* find_person(Card* list, size_t size) {
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
                return list + i;
            }
        }
        printf("person not found\n");
        return NULL;
    case 2:
        printf("print surname, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        for (i = 0; i < size; i++) {
            if (strcmp(list[i].surname, buf) == 0) {
                return list + i;
            }
        }
        printf("person not found\n");
        return NULL;
    case 3:
        printf("print number, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        for (i = 0; i < size; i++) {
            if (strcmp(list[i].number, buf) == 0) {
                return list + i;
            }
        }
        printf("person not found\n");
        return NULL;
    default:
        printf("wrong value\n");
        return NULL;
    }
}

void edit_person(Card* current) {
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
        strcpy(current->name, buf);
        return;
    case 2:
        printf("print surname, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        strcpy(current->surname, buf);
        return;
    case 3:
        printf("print number, %d charachters max\n", STRSZ - 1);
        read_field(buf);
        strcpy(current->number, buf);
        return;
    default:
        printf("wrong value\n");
        return;
    }
}

void delete_person(Card* current, Card* list, size_t* szptr) {
    size_t i = current - list + 1;
    for (i; i < *szptr; i++) {
        list[i - 1] = list[i];
    }
    *szptr -= 1;
}

void view_person(Card* current) {
    printf("\n");
    fputs(current->name, stdout);
    printf("\n");
    fputs(current->surname, stdout);
    printf("\n");
    fputs(current->number, stdout);
    printf("\n\n");
}

void view_list(Card* list, size_t size) {
    size_t i;
    for (i = 0; i < size; i++) {
        view_person(list + i);
    }
}

void demo_fill(Card* list, size_t *size) {
    // размер списка (arrsz) не меньше 3!
    Card vasya = {
        .name = {'v', 'a', 's', 'y', 'a', '\0'},
        .surname = {'p', 'u', 'p', 'k', 'i', 'n', '\0'},
        .number = {'1', '2', '3', '4', '\0'}
        };
    *list = vasya;
    *size += 1;
    list++;
    Card petya = {
        .name = {'p', 'e', 't', 'y', 'a', '\0'},
        .surname = {'g', 'u', 'b', 'k', 'i', 'n', '\0'},
        .number = {'4', '3', '2', '1', '\0'}
        };
    *list = petya;
    *size += 1;
    list++;
    Card vova = {
        .name = {'v', 'o', 'v', 'a', '\0'},
        .surname = {'d', 'u', 'd', 'k', 'i', 'n', '\0'},
        .number = {'1', '1', '1', '1', '\0'}
        };
    *list = vova;
    *size += 1;
    list++;
}

int main() {
    const char* menu;
    menu = "Choose option:\
    \n1. view list\
    \n2. find person\
    \n3. add person\
    \n4. edit person\
    \n5. delete person\n";
    Card list[ARRSZ];
    size_t size = 0;
    demo_fill(list, &size);
    int selector;
    Card* current;
    while (1) {
        printf("%s", menu);
        scanf("%d", &selector);
        while (fgetc(stdin) != '\n') {}
        switch (selector) {
        case 1:
            view_list(list, size);
            break;
        case 2:
            current = find_person(list, size);
            if (current != NULL) {
                view_person(current);
            }
            break;
        case 3:
            add_person(list, &size);
            break;
        case 4:
            current = find_person(list, size);
            if (current != NULL) {
                edit_person(current);
            }
            break;
        case 5:
            current = find_person(list, size);
            if (current != NULL) {
                delete_person(current, list, &size);
            }
            break;
        default:
            printf("wrong value\n");
        }
    }
}
