#include "gen.h"
#include "liters.h"

int generator_template(char *input, char **output)
{
	int i, j, k = 0;
	int length = 0;
	
	if (input == NULL) {
		return -1; // нулевая строка
	}
	for (i = 0; i < strlen(input); i++) {
		if (input[i] == 'c' || input[i] == 'C' || input[i] == 'd' ||
		    input[i] == 's' || input[i] == '?') {
			
			if (input[i] == '?' && i < strlen(input)) {
				i++;
				k++;
				while (input[i] != '?' && i < strlen(input)) {
					
					i++;
				}
				if (input[i] == '?')
					k++;			
			}
				
		} else
				return -3; // symbol not from dict
	}
	
	if (k % 2 != 0)
		return -2;// once ?
			
	char *out = calloc(strlen(input), sizeof(char));
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
                seed = seed % strlen(upperCase);
                out[i] = upperCase[seed];
                length++;
                break;
            case 'c':
                seed = seed % strlen(lowerCase);
                out[i] = lowerCase[seed];
                length++;
                break;
            case 'd':
                seed = seed % strlen(digits);
                out[i] = digits[seed];
                length++;
                break;
            case 's':
                seed = seed % strlen(symbols);
                out[i] =symbols[seed];
                length++;
                break;
            case '?':
             out[i] = input[i];
                i++;
                while (input[i] !='?') {
                    out[i] = input[i];
                    length++;
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
	
	out[length] = '\0';
	*output = out;
	return 0; // All is OK
}


void default_gen(PassGenOptions options, char *pass)
{
    int k, index;
    
	//hash
    char *str_data = NULL;
    char *h = NULL;
    data(&str_data);
    hash(str_data, &h);
    int seed = 0;

    for (int i = 0; i < options.pass_size; ++i)
    {
		for (int j = 0; h[j] != '\0'; j++) 
		{
			seed = seed + h[j];
		}
		
        k = seed % options.pass_strength;

        switch (k)
        {
            case 0:
                index = seed % sizeLowerCase;
                pass[i] = lowerCase[index];
                break;
            case 1:
                index = seed % sizeUpperCase;
                pass[i] = upperCase[index];
                break;
            case 2:
                index = seed % sizeDigits;
                pass[i] = digits[index];
                break;
            case 3:
                index = seed % sizeSymbols;
                pass[i] = symbols[index];
                break;
        }
        hash(h, &h);
    }
    pass[options.pass_size] = '\0';
}
