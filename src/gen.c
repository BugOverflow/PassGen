#include "gen.h"

char *generator_template(char* seed, char *input)
{
	char A[] = {'0','1','2','3','4','5','6','7','8','9'};
	char B[] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
	char C[] = {'!','@','#','$','%','^','&','*','(',')'};
	char D[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	
	char *out = malloc(sizeof(char) * strlen(input));
    int i;

    for (i = 0; i < strlen(input); i++) {
        switch (inputp[i]) {
            case C:
                out[i] = B[];
                break;
            case c:
                out[i] = D[];
                break;
            case d:
                out[i] = A[];
                break;
            case s:
                out[i] =C[];
            
        }
    }
	return out;
}

char *generator_default(char *input, int complexity)
{
}

char *hash(char *input_seed);
{
    md5_state_t HASH;
    md5_byte_t digest[16];
    char hex_output[16*2 + 1];
    int di;
    
    md5_init(&HASH);
    md5_append(&HASH, (const md5_byte_t *)input_seed, strlen(input_seed));
    md5_finish(&HASH, digest);
    
    for (di = 0; di < 16; ++di) {
	    sprintf(hex_output + di * 2, "%02x", digest[di]);
    }
    return hex_output;
}
