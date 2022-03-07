#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "phonebook.h"
#include "../my_darray/my_darray.h"

int main() {
    const char* menu;
    menu = "Choose option:\
    \n1. view list\
    \n2. find person\
    \n3. add person\
    \n4. edit person\
    \n5. delete person\
    \n0. exit\n";
    int selector;
    void* current;
    void* list = myda_create(sizeof(Card),0);
    demo_fill(&list);
    while (1) {
        printf("%s", menu);
        scanf("%d", &selector);
        while (fgetc(stdin) != '\n') {}
        switch (selector) {
	case 0:
	    myda_destroy(list, NULL);
	    return 0;
        case 1:
            view_list(list);
            break;
        case 2:
            current = find_person(list);
            if (current != NULL) {
                view_person(current);
            }
            break;
        case 3:
            add_person(&list);
            break;
        case 4:
            current = find_person(list);
            if (current != NULL) {
                edit_person(current);
            }
            break;
        case 5:
            current = find_person(list);
            if (current != NULL) {
                delete_person(&list, current);
            }
            break;
        default:
            printf("wrong value\n");
        }
    }
}
