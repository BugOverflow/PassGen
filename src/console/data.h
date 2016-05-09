#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>

char *read_pipe(FILE *input);
void data(char **str);
double wtime();

#endif
