#include <stdlib.h>
#include <unistd.h> // getopt
#include <stdio.h>

#include "options.h"

void parse_options(int argc, char * argv[], struct PassOptions * p_opt)
{
	p_opt->count = 0;
	p_opt->strength = 0;

	int opt;
	opterr = 0; // запретить вывод ошибок от getopt()
	while ((opt = getopt(argc, argv, "hvs:c:")) != -1)
	{
		switch (opt)
		{
			case '?':
			case 'h':
				printf("Basic usage: \"PassGen -c <count> -s <strength>\"\n");
				break;
			case 'v':
				printf("Version 0.0\n");
				break;
			case 's':
				// сложность пароля
				p_opt->strength = atoi(optarg);
				break;
			case 'c':
				// количество символов
				p_opt->count = atoi(optarg);
				break;
		}
	}
}
