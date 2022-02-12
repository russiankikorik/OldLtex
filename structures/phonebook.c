#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARRSZ 10
#define STRSZ 16

typedef struct {
    char name[STRSZ];
    char surname[STRSZ];
    char number[STRSZ];
} Card;

bool my_str_cmp(char* a, char* b) {
    size_t i;
    for (i = 0; i < STRSZ; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void free_card(Card* current) {
    size_t i;
    size_t sz = sizeof(Card);
    for (i = 0; i < sz; i++) {
        ((char*) current) [i] = 0;
    }
}

void init_list(Card* list) {
    size_t i;
    for (i = 0; i < ARRSZ; i++) {
        free_card(list + i);
    }
}


void add_person(Card* list, size_t* szptr) {
    if (*szptr == ARRSZ) {
        printf("list is full\n");
        return;
    }
    printf("print name, %d charachters max\n", STRSZ - 1);
    fgets(list[*szptr].name, STRSZ, stdin);
    // while (fgetc(stdin)!='\n') {}
    printf("print surname, %d charachters max\n", STRSZ - 1);
    fgets(list[*szptr].surname, STRSZ, stdin);
    // while (fgetc(stdin)!='\n') {}
    printf("print number, %d charachters max\n", STRSZ - 1);
    fgets(list[*szptr].number, STRSZ, stdin);
    // while (fgetc(stdin)!='\n') {}
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
        fgets(buf, STRSZ, stdin);
        // while (fgetc(stdin)!='\n') {}
        for (i = 0; i < size; i++) {
            if (my_str_cmp(list[i].name, buf)) {
                return list + i;
            }
        }
        printf("person not found\n");
        return NULL;
    case 2:
        printf("print surname, %d charachters max\n", STRSZ - 1);
        fgets(buf, STRSZ, stdin);
        // while (fgetc(stdin)!='\n') {}
        for (i = 0; i < size; i++) {
            if (my_str_cmp(list[i].surname, buf)) {
                return list + i;
            }
        }
        printf("person not found\n");
        return NULL;
    case 3:
        printf("print number, %d charachters max\n", STRSZ - 1);
        fgets(buf, STRSZ, stdin);
        // while (fgetc(stdin)!='\n') {}
        for (i = 0; i < size; i++) {
            if (my_str_cmp(list[i].number, buf)) {
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
        fgets(buf, STRSZ, stdin);
        // while (fgetc(stdin)!='\n') {}
        for (i = 0; i < STRSZ; i++) {
            (current->name) [i] = 0;
        }
        for (i = 0; i < STRSZ; i++) {
            (current->name) [i] = buf[i];
        }
        return;
    case 2:
        printf("print surname, %d charachters max\n", STRSZ - 1);
        fgets(buf, STRSZ, stdin);
        // while (fgetc(stdin)!='\n') {}
        for (i = 0; i < STRSZ; i++) {
            (current->surname) [i] = 0;
        }
        for (i = 0; i < STRSZ; i++) {
            (current->surname) [i] = buf[i];
        }
        return;
    case 3:
        printf("print number, %d charachters max\n", STRSZ - 1);
        fgets(buf, STRSZ, stdin);
        // while (fgetc(stdin)!='\n') {}
        for (i = 0; i < STRSZ; i++) {
            (current->number) [i] = 0;
        }
        for (i = 0; i < STRSZ; i++) {
            (current->number) [i] = buf[i];
        }
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
    free_card(list + *szptr);
}

void view_person(Card* current) {
    fputs(current->name, stdout);
    // printf("\n");
    fputs(current->surname, stdout);
    // printf("\n");
    fputs(current->number, stdout);
    // printf("\n");
}

void view_list(Card* list, size_t size) {
    size_t i;
    for (i = 0; i < size; i++) {
        view_person(list + i);
        printf("\n");
    }
}

void demo_fill(Card* list, size_t *size) {
    // размер списка не меньше 3!
    Card vasya = { .name = {'v', 'a', 's', 'y', 'a', '\n'}, .surname = {'p', 'u', 'p', 'k', 'i', 'n', '\n'}, .number = {'1', '2', '3', '4', '\n'}};
    *list = vasya;
    *size += 1;
    list++;
    Card petya = { .name = {'p', 'e', 't', 'y', 'a', '\n'}, .surname = {'g', 'u', 'b', 'k', 'i', 'n', '\n'}, .number = {'4', '3', '2', '1', '\n'}};
    *list = petya;
    *size += 1;
    list++;
    Card vova = { .name = {'v', 'o', 'v', 'a', '\n'}, .surname = {'d', 'u', 'd', 'k', 'i', 'n', '\n'}, .number = {'1', '1', '1', '1', '\n'}};
    *list = vova;
    *size += 1;
    list++;
}

int main() {
    const char* menu;
    menu = "Choose option:\n1. view list\n2. find person\n3. add person\n4. edit person\n5. delete person\n";
    Card list[ARRSZ];
    init_list(list);
    size_t size = 0;
    demo_fill(list, &size);
    int selector;
    Card* current;
    while (true) {
        printf(menu);
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
