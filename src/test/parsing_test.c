#include "ctest.h"
#include "../console/parsing.h"

CTEST(parsing, test_1)
{
    char *input = malloc(80 * sizeof(char));
    char *output;
    int flg;
    
    input = "C4s3d2c1d3c2?qwert?";
    
    flg = parsing(input, &output);
    
    
}
