#include "ctest.h"
#include "../console/gen.h"
#include "../console/application.h"
#include <string.h>

CTEST(default_gen, return_test)
{
    PassGenOptions options = { MODE_DEFAULT, 0, 0, NULL };
    options.pass_size = 5;
    options.pass_strength = 3;
    int flg;
    char *pass = calloc(options.pass_size, sizeof(char));
    flg = default_gen(options, pass);
    ASSERT_EQUAL(0, flg);
    ASSERT_NOT_NULL(pass);
    ASSERT_EQUAL(5, strlen(pass));
    free(pass);
}

CTEST(default_gen, incorrect_length_password_1)
{
    PassGenOptions options = { MODE_DEFAULT, 0, 0, NULL };
    options.pass_size = 0;
    options.pass_strength = 3;
    int flg;
    char *pass = calloc(options.pass_size, sizeof(char));
    flg = default_gen(options, pass);
    ASSERT_EQUAL(-1, flg);
    ASSERT_EQUAL(0, strlen(pass));
    free(pass);
}

CTEST(default_gen, incorrect_length_password_2)
{
    PassGenOptions options = { MODE_DEFAULT, 0, 0, NULL };
    options.pass_size = 64;
    options.pass_strength = 3;
    int flg;
    char *pass = calloc(options.pass_size, sizeof(char));
    flg = default_gen(options, pass);
    ASSERT_EQUAL(-1, flg);
    ASSERT_EQUAL(0, strlen(pass));
}

CTEST(default_gen, incorrect_strength_password_1)
{
    PassGenOptions options = { MODE_DEFAULT, 0, 0, NULL };
    options.pass_size = 10;
    options.pass_strength = 8;
    int flg;
    char *pass = calloc(options.pass_size, sizeof(char));
    flg = default_gen(options, pass);
    ASSERT_EQUAL(-2, flg);
    ASSERT_EQUAL(0, strlen(pass));
    free(pass);
}

CTEST(default_gen, incorrect_strength_password_2)
{
    PassGenOptions options = { MODE_DEFAULT, 0, 0, NULL };
    options.pass_size = 10;
    options.pass_strength = -1;
    int flg;
    char *pass = calloc(options.pass_size, sizeof(char));
    flg = default_gen(options, pass);
    ASSERT_EQUAL(-2, flg);
    ASSERT_EQUAL(0, strlen(pass));
    free(pass);
}
