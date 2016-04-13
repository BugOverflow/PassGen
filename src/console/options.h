#ifndef OPTIONS_H
#define OPTIONS_H

#include <string.h>

enum PassMode
{
    MODE_DEFAULT = 0,
    MODE_TEMPLATE = 1
};

struct PassOptions
{
    int mode;
	int count;
    char * template;
};

void parse_options(int argc, char * argv[], struct PassOptions * p_opt);

#endif
