#include "application.h"

PassGenOptions options = { MODE_DEFAULT, 0, NULL };

int run(int argc, char **argv)
{
	parse_options(argc, argv);
	
	return 0;
}

void parse_options(int argc, char **argv)
{
	//p_opt->mode = MODE_DEFAULT;
	//p_opt->count = 0;
    //p_opt->template = NULL;
    
	//int opt;
	//opterr = 0; // запретить вывод ошибок от getopt()
	//while ((opt = getopt(argc, argv, "hvt:dc:")) != -1)
	//{
		//switch (opt)
		//{
            //default: /* '?' */
			//case 'h':
				//printf("Basic usage: \"PassGen \"\n");
				//break;
			//case 'v':
				//printf("Version 0.0\n");
				//break;
            //case 't':
                //p_opt->mode = MODE_TEMPLATE;
                //// шаблон
                //p_opt->template = malloc(sizeof(char) * strlen(optarg));
                //strncpy(p_opt->template, optarg, strlen(optarg));
                //break;
            //case 'd':
                //p_opt->mode = MODE_DEFAULT;
                //break;
			//case 'c':
				//// количество символов
				//p_opt->count = atoi(optarg);
				//break;
		//}
	//}
}
