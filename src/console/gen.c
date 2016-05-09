#include "gen.h"
#include "liters.h"

char *generator_template(char *input)
{
	assert(input);
	
	int i, j, k = 0;
	
	for (i = 0; (input[i] != '\0'); i++) {
		assert((input[i] == '?') || (input[i] == 'c') || (input[i] == 'd') || (input[i] == 's') || (input[i] == '\0') || (input[i] == 'C'));
		if ( input[i] == '?') {
			assert(input[i] != input[i + 1]);
			k++;
			do {
				i++;
				if ( input[i] == '?') {
					k++;
					break;
				}
			} while ((input[i] != '?') && input[i] != '\0');
		}
	}
	assert(k % 2 == 0);
	
	char NUM[] = {'0','1','2','3','4','5','6','7','8','9', '\0'};
	char UP[] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M', '\0'};
	char SYM[] = {'!','@','#','$','%','^','&','*','(',')', '\0'};
	char DOWN[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m', '\0'};
	
	char *out = malloc(sizeof(char) * strlen(input));
    char *str_data = NULL;
    char *h = NULL;
    data(&str_data);
    hash(str_data, &h);
    int seed = 0;
    
    
    for (i = 0; i < strlen(input); i++) {
		for (j = 0; h[j] != '\0'; j++) {
			seed = seed + h[j];
		}
		
        switch (input[i]) {
            case 'C':
                seed = seed % strlen(UP);
                out[i] = UP[seed];
                break;
            case 'c':
                seed = seed % strlen(DOWN);
                out[i] = DOWN[seed];
                break;
            case 'd':
                seed = seed % strlen(NUM);
                out[i] = NUM[seed];
                break;
            case 's':
                seed = seed % strlen(SYM);
                out[i] =SYM[seed];
                break;
            case '?':
             out[i] = input[i];
                i++;
                while (input[i] !='?') {
                    out[i] =input[i];
                    i++;
                }
                out[i] = input[i];
                break;
        }
        hash(h, &h);
    }
    
    for (i = 0; out[i] != '\0'; i++) {
		if ((out[i] == '?') && (out[i + 1] == '?')) {
			for (j = i; out[j] != '\0'; j++) {
				out[j] = out[j + 2];
			}
		} else if (out[i] == '?') {
			for (j = i; out[j] != '\0'; j++) {
				out[j] = out[j + 1];
			}
		}
	}
	out[strlen(input)] = '\0';
	return out;
}

/* getrand: Returns random number from [min, max) */
int get_rand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void default_gen(PassGenOptions options, char *pass)
{
    int k, index;

    for (int i = 0; i < options.pass_size; ++i)
    {
        k = i % options.pass_strength;

        switch (k)
        {
            case 0:
                index = get_rand(0, sizeLowerCase - 1);
                pass[i] = lowerCase[index];
                break;
            case 1:
                index = get_rand(0, sizeUpperCase - 1);
                pass[i] = upperCase[index];
                break;
            case 2:
                index = get_rand(0, sizeDigits - 1);
                pass[i] = digits[index];
                break;
            case 3:
                index = get_rand(0, sizeSymbols - 1);
                pass[i] = symbols[index];
                break;
        }
    }
    pass[options.pass_size] = '\0';
    //pass[data.pass_size + 1] = '\n';
}
