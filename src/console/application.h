#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdlib.h>
#include <unistd.h>

typedef enum {
    MODE_DEFAULT = 0,
    MODE_TEMPLATE = 1
} PassGenMode;

typedef struct {
    PassGenMode mode;
	int pass_size;
    char *template;
} PassGenOptions;

int run(int argc, char **argv);
void parse_options(int argc, char **argv);

#endif
