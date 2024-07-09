#include <stdio.h>
#include "htol.h"

int main()
{
	char hex1[] = "0x23FA"; // 9210
	long correct_h1 = 9210;
	printf("Integer(long) for %s is %ld and it should be %ld\n", hex1, htol(hex1), correct_h1);

	char hex2[] = "0X985ef"; // 624111
	long correct_h2 = 624111;
	printf("Integer(long) for %s is %ld and it should be %ld\n", hex2, htol(hex2), correct_h2);

	char hex3[] = "0X1093AeF";
	long correct_h3 = 17382127;
   	printf("Integer(long) for %s is %ld and it should be %ld\n", hex3, htol(hex3), correct_h3);	
	
	return 0;
}

