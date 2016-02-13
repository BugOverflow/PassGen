#ifndef OPTIONS_H
#define OPTIONS_H

struct PassOptions
{
	int count;
	int strength;
};

void parse_options(int argc, char * argv[], struct PassOptions * p_opt);

#endif
