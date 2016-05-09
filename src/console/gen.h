#ifndef GEN_H
#define GEN_H

#include <stdlib.h>
#include "md5.h"
#include "hash.h"
#include <assert.h>
#include "data.h"
#include "application.h"

char* generator_template(char *input);
int get_rand(int min, int max);
void default_gen(PassGenOptions data, char *pass);

#endif
