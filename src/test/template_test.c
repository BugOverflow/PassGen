#include "ctest.h"
#include "../console/gen.h"
#include <stdio.h>

CTEST(gen_template, return_test)
{
    char *input = malloc(80 * sizeof(char));
    char *output;
    int flg;

    sprintf(input, "%s", "?cat?ddddddddddssssssCCCCc");

    flg = generator_template(input, &output);
    ASSERT_EQUAL(0, flg);
    free(input);
}

CTEST(gen_template, NULL_input_test)
{
    char *input = NULL;
    char *output = NULL;
    int flg;

    flg = generator_template(input, &output);
    ASSERT_EQUAL(-1, flg);
    free(input);
}

CTEST(gen_template, char_not_dictionary)
{
    char *input = malloc(80 * sizeof(char));
    char *output = NULL;
    int flg;

    sprintf(input, "%s", "ccp");

    flg = generator_template(input, &output);
    ASSERT_EQUAL(-3, flg);
    free(input);
}

CTEST(gen_template, no_question_key_test)
{
    char *input = malloc(80 * sizeof(char));
    char *output = NULL;
    int flg;

    sprintf(input, "%s", "sdddd?cat");

    flg = generator_template(input, &output);
    ASSERT_EQUAL(-2, flg);
    free(input);
}
