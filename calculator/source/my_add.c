#include "pluginfo.h"

Pluginfo pluginfo = {"my_add", "add", 2};

double my_add(double* arglist) {
    return arglist[0] + arglist[1];
}
