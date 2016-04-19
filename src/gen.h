#ifndef GEN_H
#define GEN_H

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../md5.h"

char* generator_template(char *input);
char* generator_default(char *input, int complexity);
char* hash(char *input_seed);

#endif
