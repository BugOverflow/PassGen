#include "input.h"

Data input(int argc, char *argv[])
{
	const char *KEYS = "t:ds:c:"; //arg keys
	opterr = 0;

	Data values;
	values.templ = NULL;
	values.mode = 0;
	values.strong = -1;
	values.count = -1;

	int c;
	while ((c = getopt(argc, argv, KEYS)) != -1) // reading args
	{
		switch (c)
		{
			case 't': // template mode
				if ( (values.mode == 0) && (values.count == -1) && (values.strong == -1) )
				{
					values.mode = -1;
					values.templ = optarg;
					break;
				}
				else
				{
					fprintf(stderr, "Too many arguments for template mode! Please, try again.\n");
					values.err = 1;
				}
			case 'd': // default mode
				if (values.mode == 0)
				{
					values.mode = 1;
					break;
				}
				else
				{
					fprintf(stderr, "Unknown mode! Please, try again.\n");
					values.err = 1;
				}
			case 's': // password difficulty
				if (values.mode != -1)
				{
					int tmp = atoi(optarg);
					if (tmp > 0)
					{
						values.strong = tmp;
						break;
					}
					else
					{
						fprintf(stderr, "Wrong value of strong mode! Please, try again.\n");
						values.err = 1;	
					}	
				}
				else
				{
					fprintf(stderr, "Too many arguments for template mode! Please, try again.\n");
					values.err = 1;
				}
			case 'c': // values.count of password symbols
				if (values.mode != -1)
				{
					int tmp = atoi(optarg);
					if (tmp > 0)
					{
						values.count = tmp;
						break;
					}
					else
					{
						fprintf(stderr, "Wrong value of password lenght! Please, try again.\n");
						values.err = 1;
					}
				}
				else
				{
					fprintf(stderr, "Too many arguments for template mode! Please, try again.\n");
					values.err = 1;	
				}
			case '?':
        		if (optopt == 'c')
          			fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        		else if (isprint (optopt))
          			fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        		else
          			fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        		values.err = 1;	
      		default:
        		abort ();
      }
	}
    printf("Mode: %d values.templ: %s\n", values.mode, values.templ);
    printf("Dmode: %d\n", values.mode);
    printf("values.strong: %d\n", values.strong);
    printf("values.count: %d\n", values.count);
    printf("Error: %d\n", values.err);
    //return values;
}