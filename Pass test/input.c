// #include "options.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

opterr = 0;
const char KEYS[]= "t:ds:c:"; //arg keys
int tumbler = 0; // unknown mode
int strong = -1, count = -1;
char *templ; // template of password

int main(int argc, char *argv[])
{
	int c;
	while ((c = getopt(argc, argv, KEYS)) != -1) // reading args
	{
		switch (c)
		{
			case 't': // template mode
				if ( (tumbler == 0) && (count == -1) && (strong == -1) )
				{
					tumbler = -1;
					templ = optarg;
					break;
				}
				else
				{
					fprintf(stderr, "Too many arguments for template mode! Please, try again.\n", optopt);
					return 1;	
				}
			case 'd': // default mode
				if (tumbler == 0)
				{
					tumbler = 1;
					break;
				}
				else
				{
					fprintf(stderr, "Unknown mode! Please, try again.\n", optopt);
					return 1;	
				}
			case 's': // password difficulty
				if (tumbler != -1)
				{
					int tmp = atoi(optarg);
					if (tmp > 0)
					{
						strong = tmp;
						break;
					}
					else
					{
						fprintf(stderr, "Wrong value of strong mode! Please, try again.\n", optopt);
						return 1;
					}	
				}
				else
				{
					fprintf(stderr, "Too many arguments for template mode! Please, try again.\n", optopt);
					return 1;
				}
			case 'c': // count of password symbols
				if (tumbler != -1)
				{
					int tmp = atoi(optarg);
					if (tmp > 0)
					{
						count = tmp;
						break;
					}
					else
					{
						fprintf(stderr, "Wrong value of password lenght! Please, try again.\n", optopt);
						return 1;
					}
				}
				else
				{
					fprintf(stderr, "Too many arguments for template mode! Please, try again.\n", optopt);
					return 1;	
				}
			case '?':
        		if (optopt == 'c')
          			fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        		else if (isprint (optopt))
          			fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        		else
          			fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        		return 1;
      		default:
        		abort ();
      }
	}
    printf("Mode: %d TEMPL: %s\n", tumbler, templ);
    printf("Dmode: %d\n", tumbler);
    printf("strong: %d\n", strong);
    printf("Count: %d\n", count);
    return 0;
}