#include <math.h>
#include "pluginfo.h"

Pluginfo pluginfo = {"my_sqrt", "square root", 1};

double my_sqrt(double* arglist) {
    double ans = sqrt(arglist[0]);
    return ans;
}
