#include <stdio.h>
#include <stdlib.h>

#include "options.h"

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("Missing arguments! See help: \"PassGen -h\"\n");
	}
	
	struct PassOptions pass_options;
	parse_options(argc, argv, &pass_options);
	
    // TEST	
	printf("%d %d %s %d", pass_options.count, pass_options.strength, pass_options.template, pass_options.mode);
    
    
    // Освобождаем под конец
    free(pass_options.template);

	return 0;
}
