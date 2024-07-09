#include <stdio.h>
#include "atoi.h"

int main()
{
	char *s1 = "1241";
	printf("%d\n", atoi(s1));

	char *s2 = "-12333";
	printf("%d\n", atoi(s2));

	char *s3 = "-345da553";
	printf("%d\n", atoi(s3));

	return 0;
}

