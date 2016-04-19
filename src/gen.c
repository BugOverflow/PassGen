#include "gen.h"

char *generator_template(char* seed, char *input)
{
	char A[] = {'0','1','2','3','4','5','6','7','8','9'};
	char B[] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
	char C[] = {'!','@','#','$','%','^','&','*','(',')'};
	char D[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	
	char *out = malloc(sizeof(char) * strlen(input));
    int i;

    FILE *file_data;
    file_data = fopen("PATH", "r");
    char data[1024];
    fgets(data, 1024, file_data);
        
    char *h = hash(file_data);
    int seed;
    
    for (i = 0; i < strlen(input); i++) {
        switch (inputp[i]) {
            case C:
                seed = h[i % strlen(input)] * wtime() % strlen(B);
                out[i] = B[seed];
                break;
            case c:
                seed = h[i % strlen(input)] * wtime() % strlen(D);
                out[i] = D[seed];
                break;
            case d:
                seed = h[i % strlen(input)] * wtime() % strlen(A);
                out[i] = A[seed];
                break;
            case s:
                seed = h[i % strlen(input)] * wtime() % strlen(s);
                out[i] =C[seed];
            
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
