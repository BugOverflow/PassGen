#include "../sr/console/cgen.h"

int main(int argc, char **argv)
{
	char *t = argv[1];
	char *tmp = NULL;
	tmp = generator_template(t);
	printf("%s\n", tmp);
	return 0;
}
