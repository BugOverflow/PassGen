#include "application.h"
#include "liters.h"

PassGenOptions options = { MODE_DEFAULT, 0, 0, NULL };
PassGenError err = { ERR_NO, "" };

int run(int argc, char **argv)
{
    parse_options(argc, argv);

    fprintf(stderr, "Err: %d, %s \n", err.code, err.message);

    char word[options.pass_size];
    default_gen(options, word);
    printf("%s\n", word);
    FILE *output = fopen("test.txt", "w");
    fprintf(output, "%s", word);
    fclose(output);


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
                        if (tmp > 0)
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








/* getrand: Returns random number from [min, max) */
int get_rand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void default_gen(PassGenOptions data, char *pass)
{
    int k, index;

    for (int i = 0; i < data.pass_size; ++i)
    {
        k = i % data.pass_strength;

        switch (k)
        {
            case 0:
                index = get_rand(0, sizeLowerCase - 1) % sizeLowerCase;
                pass[i] = lowerCase[index];
                break;
            case 1:
                index = get_rand(0, sizeUpperCase - 1) % sizeLowerCase;
                pass[i] = upperCase[index];
                break;
            case 2:
                index = get_rand(0, sizeDigits - 1) % sizeDigits;
                pass[i] = digits[index];
                break;
            case 3:
                index = get_rand(0, sizeSymbols - 1) % sizeSymbols;
                pass[i] = symbols[index];
                break;
        }
    }
    
    //pass[data.pass_size + 1] = '\n';
}
