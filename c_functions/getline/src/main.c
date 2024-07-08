#include <stdio.h>
#include "get_line.h"

int main()
{
	int length = 10;
	char line[length];
	get_line(line, length);

	printf("%s\n", line);

	return 0;
}


