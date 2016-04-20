#ifndef INPUT
#define INPUT

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct idatei
{
	int err;
	int mode;
	int strong;
	int count;
	char *templ;
} Data;

Data input(int argc, char *argv[]);

#endif