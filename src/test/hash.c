#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../md5.h"
#include <stdio.h>

int main(int arc, char **arv)
{
    md5_state_t HASH;
    md5_byte_t digest[16];
    char hex_output[16*2 + 1];
    int di;
    char *input_seed = (arv[1]);
    
    md5_init(&HASH);
    md5_append(&HASH, (const md5_byte_t *)input_seed, strlen(input_seed));
    md5_finish(&HASH, digest);
    
    for (di = 0; di < 16; ++di) {
	    sprintf(hex_output + di * 2, "%02x", digest[di]);
    }
    printf("%s\n", hex_output);
    return 0;
}
