#include "application.h"
#include "gen.h"


PassGenOptions options = { MODE_DEFAULT, 0, 0, NULL };
PassGenError err = { ERR_NO, "\0" };

int run(int argc, char **argv)
{
	if (argc < 2) 
	{
        confreader();
    }
    else parse_options(argc, argv);

    if (err.code != ERR_NO) {
        fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
        return EXIT_FAILURE;
    }

    char *pass = NULL;
    char *s_pars = NULL;
    switch (options.mode) {
        case MODE_DEFAULT:
            pass = malloc(options.pass_size * sizeof(char));
            if (pass == NULL) {
                printf("Error of memory allocation!\n");
                return EXIT_FAILURE;
            }
            err.code = default_gen(options, pass);
	    if (err.code == -1) {
		handle_err(ERR_FUNC_DEFOULT_GEN,
                               "Incorrect length of pass!  Please, try again.");
		fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
		return EXIT_FAILURE;
	    }
	    if (err.code == -2) {
		handle_err(ERR_FUNC_DEFOULT_GEN,
                               "Incorrect strength of password!  Please, try again.");
		fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
		return EXIT_FAILURE;
	    }
	    if (err.code == -3) {
		handle_err(ERR_FUNC_DEFOULT_GEN,
                               "Error of memory allocation!");
		fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
		return EXIT_FAILURE;
	    }
            printf("%s\n", pass);
            break;

        case MODE_TEMPLATE:
            err.code = parsing(options.template, &s_pars);
            if (err.code == 0) {
                err.code = generator_template(s_pars, &pass);
                if (err.code == 0) {
                    printf("%s\n", pass);
                } else if (err.code == -2) {
                    handle_err(ERR_FUNC_TEMLATE_GEN,
                               "The second key \"?\" is not found! Please, try again.");
                    fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
                    return EXIT_FAILURE;
                } else if (err.code == -3) {
                    handle_err(ERR_FUNC_TEMLATE_GEN,
                               "Wrong key! Please, try again.");
                    fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
                    return EXIT_FAILURE;
                }
            } else if (err.code == -2) {
                handle_err(ERR_FUNC_PARSING,
                           "The second key \"?\" is not found! Please, try again.");
                fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
                return EXIT_FAILURE;
            } else if (err.code == -3) {
                handle_err(ERR_FUNC_PARSING, "Wrong key! Please, try again.");
                fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
                return EXIT_FAILURE;
            } else if (err.code == -4) {
                handle_err(ERR_FUNC_PARSING,
                           "First symbol key, is then the amount of symbols! Please, try again.");
                fprintf(stderr, "Err: %d, %s \n", err.code, err.message);
                return EXIT_FAILURE;
            }
            break;
    }
    if (!pass)
        free(pass);
    return 0;
}

void handle_err(PassGenErrCode code, char *mess)
{
    err.code = code;
    strcpy(err.message, mess);
}

void parse_options(int argc, char **argv)
{
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
                        if (tmp > 0 && tmp <= 32)
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


void check_options(PassGenOptions options)
{
  
}

int confreader()
{
    char* buff;
    char cdef[] = "DEFAULT_MODE=";
    char ctem[] = "TEMPLATE_MODE=";
    char cstren[] = "PASS_STRENGTH="; 
    char csize[] = "PASS_SIZE=";
    char ctemplate[] = "TEMPLATE=";
    
    FILE *config = fopen("PassConfig", "r");

    if (config != NULL)
    {
       while ( !feof(config) )
       {
       		int i = 0;
       		buff = calloc(128, sizeof(char));
       		while ((buff[i] = fgetc(config)) != '\n' && (buff[i] != EOF)) 
       		{
          		i++;
       		}

       		// printf("%s", buff);

       		if (sstr(buff, cdef) > -1)
           {
           		char* value = returnvalue(buff, cdef);

           		if (atoi(value) == 1)
           			options.mode = MODE_DEFAULT;
           }
           
           if (sstr(buff, ctem) > -1)
           {
           		
           		char* value = returnvalue(buff, ctem);
           		
           		if (atoi(value) == 1)
           			options.mode = MODE_TEMPLATE;
           }

           if (sstr(buff, cstren) > -1)
           {
           		char* value = returnvalue(buff, cstren);
           		int x = atoi(value);
           		options.pass_strength = x;
           }
           
          if (sstr(buff, csize) > -1)
           {
           		char* value = returnvalue(buff, csize);
           		int x = atoi(value);
           		options.pass_size = x;
           }
           
           if (sstr(buff, ctemplate) > -1)
           {
           		char* t_value = calloc(128, sizeof(char));
           		if (t_value != NULL)
           		{
           			get_template(buff, ctemplate, t_value);           		
           			options.template = t_value;
           		}
           		
           		free(t_value);
           }
           free(buff);       
       }
     	//printf("options.mode = %d\n", options.mode);
   		// printf("options.pass_strength = %d\n", options.pass_strength);
    	// printf("options.pass_size = %d\n", options.pass_size);
    	// printf("options.template: %s\n", options.template);
      fclose(config);    
    }
    else handle_err(ERR_PARSING, "Too few arguments! Please, try again.");
       
}