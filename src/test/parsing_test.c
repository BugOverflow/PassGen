#include "ctest.h"
#include "../console/parsing.h"
#include <stdio.h>

CTEST(parsing, return_test)
{
    char *input = malloc(80 * sizeof(char));
    char *output;
    int flg;
    
    sprintf(input, "%s", "C4s3d2c1d3c2?qwert?2");
    
    flg = parsing(input, &output);
    ASSERT_STR("CCCCsssddcdddcc?qwert??qwert?", output);
    ASSERT_EQUAL(0, flg);
    free(input);
}

CTEST(parsing, err_key_test)
{
    char *input = malloc(80 * sizeof(char));
    char *output = NULL;
    int flg;
    
    sprintf(input, "%s", "cdr");
    
    flg = parsing(input, &output);
    ASSERT_NULL(output);
    ASSERT_EQUAL(-3, flg);
    free(input);
}

CTEST(parsing, NULL_input_test)
{
    char *input = NULL;
    char *output = NULL;
    int flg;
    
    flg = parsing(input, &output);
    ASSERT_NULL(output);
    ASSERT_EQUAL(-1, flg);
}

CTEST(parsing, no_question_key_test)
{
    char *input = malloc(80 * sizeof(char));
    char *output = NULL;
    int flg;
    
    sprintf(input, "%s", "C4s3d2c1d3c2?qwert");
    
    flg = parsing(input, &output);
    ASSERT_EQUAL(-2, flg);
    ASSERT_NULL(output);
    free(input);
}
