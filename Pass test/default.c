#include "default.h"
#include "input.h"
#include "liters.h"
#include <stdlib.h>
#include <stdio.h>

/* getrand: Returns random number from [min, max) */
int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void defaultGen(Data options, *out)
{
	char pass[options.count];
	int k, index;

	for (short int i = 0; i < options.count; ++i)
	{
		k = i % options.strong;

		switch (k)
		{
			case 0:
				index = getrand(0, sizeLowerCase);
				pass[i] = lowerCase[index];
				break;
			case 1:
				index = getrand(0, sizeUpperCase);
				pass[i] = upperCase[index];
				break;
			case 2:
				index = getrand(0, sizeDigits);
				pass[i] = digits[index];
				break;
			case 3:
				index = getrand(0, sizeSymbols);
				pass[i] = symbols[index];
				break;
		}
	}

	out = pass;
}