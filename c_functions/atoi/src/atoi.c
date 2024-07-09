// atoi function implementaion
#include <ctype.h>

int atoi(char *s)
{
	int num; // res
	int sign;
	int index;

	for (index = 0; isspace(s[index]); ++index);

	sign = (s[index] == '-') ? -1 : 1;
	if (s[index] == '+' || s[index] == '-') {
		++index;
	}

	for (num = 0; isdigit(s[index]); ++index)
	{
		num = 10 * num + s[index] - '0';
	}

	return sign * num;
}

