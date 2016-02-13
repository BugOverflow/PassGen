#include <stdio.h>

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
	printf("%d %d", pass_options.count, pass_options.strength);

	return 0;
}
