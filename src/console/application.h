#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    MODE_DEFAULT = 0,
    MODE_TEMPLATE = 1
} PassGenMode;

typedef struct {
    PassGenMode mode;
    int pass_size;
    int pass_strength;
    char *template;
} PassGenOptions;

typedef enum {
    ERR_NO = 0,
    ERR_PARSING
} PassGenErrCode;

typedef struct {
    PassGenErrCode code;
    char message[128];
} PassGenError;

int run(int argc, char **argv);
void handle_err(PassGenErrCode code, char *mess);
void parse_options(int argc, char **argv);

#endif
