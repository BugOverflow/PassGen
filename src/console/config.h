#ifndef CONFIG_H
#define CONFIG_H

#include <string.h>
#include "application.h"

char *returnvalue(char *str, char *mode);

void get_template(char str[], char mode[], char value[]);

int confreader(char *path, PassGenOptions * options);

#endif
