#ifndef _PLUGINFO_
#define _PLUGINFO_

#define MAX_ARG_NUM 2
#define STRSZ 32
#define INFO "pluginfo"

typedef struct {
    const char symbol[STRSZ];
    const char menu_name[STRSZ];
    const int arg_number;
} Pluginfo;

#endif

