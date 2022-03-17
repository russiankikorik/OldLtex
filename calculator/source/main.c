#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include "../../my_darray/my_darray.h"
#include "pluginfo.h"

typedef struct {
    char symbol[STRSZ];
    char menu_name[STRSZ];
    int arg_number;
    char name[STRSZ];
    void* handler;
} Plugin;

double arglist[MAX_ARG_NUM];

int main() {
    struct dirent **namelist;
    size_t number_of_plugins;
    number_of_plugins = scandir("./plugins", &namelist, NULL, alphasort);
    if (number_of_plugins == -1) {
	perror("scandir");
	exit(EXIT_FAILURE);
    }
    Plugin* plugins;
    size_t i;
    char plugdir[STRSZ + 10];
    plugins = (Plugin*)myda_create(sizeof(Plugin), number_of_plugins);
    for (i = 0; i < number_of_plugins; i++) {
	strcpy(plugdir,"./plugins/");
	strcat(plugdir,namelist[i]->d_name);
	strcpy(plugins[i].name, namelist[i]->d_name);
	plugins[i].handler = dlopen(plugdir, RTLD_LAZY);
	if (plugins[i].handler) {
	    Pluginfo* pluginfo_ptr;
	    pluginfo_ptr = (Pluginfo*)dlsym(plugins[i].handler, INFO);
	    strcpy(plugins[i].symbol, pluginfo_ptr->symbol);
	    strcpy(plugins[i].menu_name, pluginfo_ptr->menu_name);
	    plugins[i].arg_number = pluginfo_ptr->arg_number;
	}
    }
    for (i = number_of_plugins; i > 0; i--) {
	free(namelist[i-1]);
    }
    free(namelist);
    for (i = 0; i < myda_size(plugins); i++) {
	if (plugins[i].handler == NULL) {
	    plugins = myda_remove(plugins, i, NULL);
	    i--;
	}
    }
    char buf[400];
    while (1) {
	int selector;
	Plugin* current;
	fprintf(stdout, "choose option:\n0. zero or nondigit to exit\n");
	for (i = 0; i < myda_size(plugins); i++) {
	    fprintf(stdout, "%lu. %s\n", i + 1, plugins[i].menu_name);
	}
	fgets(buf, 400, stdin);
	selector = (int)strtol(buf, NULL, 10);
	if (errno == ERANGE) {
	    fprintf(stdout, "overflow value\n");
	    errno = 0;
	    continue;
	}
	if (selector == 0) {break;}
	current = (Plugin*)myda_item(plugins, selector - 1);
	if (current == NULL) {
	    fprintf(stdout, "wrong value\n");
	    continue;
	}
	for (i = 0; i < MAX_ARG_NUM && i < current->arg_number; i++) {
	    fprintf(stdout, "argument %lu: ", i);
	    fgets(buf, 400, stdin);
	    arglist[i] = strtod(buf, NULL);
	    if (errno == ERANGE) {
		fprintf(stdout, "overflow or underflow occured\n");
		break;
	    }
	}
	if (errno) {
	    errno = 0;
	    continue;
	}
	double (*func)(double*);
	func = dlsym(current->handler, current->symbol);
	double answer = func(arglist);
	fprintf(stdout, "%lf\n", answer);
    }
    for (i = 0; i < myda_size(plugins); i++) {
	dlclose(plugins[i].handler);
    }
    myda_destroy(plugins, NULL);
    return 0;
}
