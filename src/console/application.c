#include "application.h"
#include "gen.h"


PassGenOptions options = { MODE_DEFAULT, 0, 0, NULL };
PassGenError err = { ERR_NO, "\0" };

int run(int argc, char **argv)
{
    parse_options(argc, argv);
	
	if (err.code != ERR_NO)
	{
		fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
	}
	    
	char *tmp = NULL, *word = NULL;
	char *t;
	
	if (options.mode == MODE_DEFAULT)
	{
		word = malloc(options.pass_size * sizeof(char));
	
		if (word == NULL)
		{
			printf("Error of memory allocation!\n");
			return EXIT_FAILURE;
		}
	}
	
	switch (options.mode)
	{
		case MODE_DEFAULT:
			default_gen(options, word);
			printf("%s\n", word);
			break;
			
		case MODE_TEMPLATE:			
			parsing(options.template, &t);			
			tmp = generator_template(t);
			printf("%s\n", tmp);
			break;
	}
    free(word);
    return 0;
}

void handle_err(PassGenErrCode code, char *mess)
{
    err.code = code;
    strcpy(err.message, mess);
}

void parse_options(int argc, char **argv)
{
    if (argc < 2) {
        handle_err(ERR_PARSING, "Need more arguments.");
        return;
    }

    const char *KEYS = "t:ds:c:";       //arg keys
    opterr = 0;

    int c;
    while ((c = getopt(argc, argv, KEYS)) != -1) {
        switch (c) {
            case 't':          // template mode
                {
                    if ((options.mode == MODE_DEFAULT) &&
                        (options.pass_size == 0) &&
                        (options.pass_strength == 0)) {
                        options.mode = MODE_TEMPLATE;
                        options.template = optarg;
                    } else
                        handle_err(ERR_PARSING,
                                   "Too many arguments for template mode! Please, try again.");
                    break;
                }
            case 'd':          // default mode
                {
                    if (options.mode == MODE_DEFAULT)
                        options.mode = MODE_DEFAULT;
                    else
                        handle_err(ERR_PARSING,
                                   "Unknown mode! Please, try again.");
                    break;
                }
            case 's':          // password difficulty
                {
                    if (options.mode != MODE_TEMPLATE) {
                        int tmp = atoi(optarg);
                        if ((tmp > 0) && (tmp < 5))
                            options.pass_strength = tmp;
                        else
                            handle_err(ERR_PARSING,
                                       "Wrong value of strong mode! Please, try again.");
                    } else
                        handle_err(ERR_PARSING,
                                   "Too many arguments for template mode! Please, try again.");
                    break;
                }
            case 'c':          // count of password symbols
                {
                    if (options.mode != MODE_TEMPLATE) {
                        int tmp = atoi(optarg);
                        if (tmp > 0)
                            options.pass_size = tmp;
                        else
                            handle_err(ERR_PARSING,
                                       "Wrong value of password lenght! Please, try again.");
                    } else
                        handle_err(ERR_PARSING,
                                   "Too many arguments for template mode! Please, try again.");
                    break;
                }
            case '?':
                {
                    if (optopt == 'c' || optopt == 't')
                        handle_err(ERR_PARSING,
                                   "This option requires an argument.");
                    else if (isprint(optopt))
                        handle_err(ERR_PARSING, "Unknown option.");
                    else
                        handle_err(ERR_PARSING, "Unknown option character.");
                }
            default:
                break;
        }
    }
}








