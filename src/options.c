#include <stdlib.h>
#include <unistd.h> // getopt
#include <stdio.h>

#include "options.h"

void parse_options(int argc, char * argv[], struct PassOptions * p_opt)
{
    p_opt->mode = MODE_DEFAULT;
	p_opt->count = 0;
    p_opt->template = NULL;
    
	int opt;
	opterr = 0; // запретить вывод ошибок от getopt()
	while ((opt = getopt(argc, argv, "hvt:dc:")) != -1)
	{
		switch (opt)
		{
            default: /* '?' */
			case 'h':
				printf("Basic usage: \"PassGen \"\n");
				break;
			case 'v':
				printf("Version 0.0\n");
				break;
            case 't':
                p_opt->mode = MODE_TEMPLATE;
                // шаблон
                p_opt->template = malloc(sizeof(char) * strlen(optarg));
                strncpy(p_opt->template, optarg, strlen(optarg));
                break;
            case 'd':
                p_opt->mode = MODE_DEFAULT;
                break;
			case 'c':
				// количество символов
				p_opt->count = atoi(optarg);
				break;
		}
	}
}
