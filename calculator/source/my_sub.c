#include "pluginfo.h"

Pluginfo pluginfo = {"my_sub", "subtract", 2};

double my_sub(double* arglist) {
    return arglist[0] - arglist[1];
}
