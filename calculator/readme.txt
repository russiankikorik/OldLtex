Для статической линковки my_darray используется make или make_static
Для динамической линковки my_darray используется make use_dynamic
Библиотеки и заголовочный файл должны быть расположены в ../my_darray

Плагин должен содержать следующую глобально объявленную стрктуру под именем pluginfo:

typedef struct {
    const char symbol[STRSZ];
    const char menu_name[STRSZ];
    const int arg_number;
} Pluginfo;

Функция должна принимать массив аргументов типа double и возвращать ответ типа double.
Пример:

#include "pluginfo.h"

Pluginfo pluginfo = {"my_add", "add", 2};

double my_add(double* arglist) {
    return arglist[0] + arglist[1];
}


