#ifndef GEN_H
#define GEN_H

#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "md5.h"
#include "hash.h"

#define size_data 256

char* generator_template(char *input);
char* generator_default(char *input, int complexity);
void data(char **str);
double wtime();


#endif
