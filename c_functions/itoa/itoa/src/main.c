#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "itoa.h"

int main()
{
	int num = 401;
	char s[12];
	itoa(num, s);
	printf("string representation of %d is %s\n", num, s);

	num = -312;
	itoa(num, s);
	printf("string representation of %d is %s\n", num, s);

	num = -2147483648;
	itoa(num, s);
	printf("string representation of %d is %s\n", num, s);

	return 0;
}

