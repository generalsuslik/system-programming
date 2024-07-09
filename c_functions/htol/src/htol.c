// htol function converts hex number,
// that starts with a 0x or 0X to long type

#include <math.h>

#define HEX_BASE 16 

// takes hex num as a string and converts it to long
long htol(char hex[])
{
	// getting the length of a hex num
	int size;
	for (size = 0; hex[size] != '\0'; ++size);

	long res = 0;
	char hex_digit;
	// starting with i = 2, cuz hex[0] = '0' and hex[1] = 'x' or 'X'
	for (int i = 2; i < size; ++i)
	{
		hex_digit = hex[i];
		if ('0' <= hex_digit && hex_digit <= '9') {
			res += (hex_digit - '0') * pow(HEX_BASE, size - i - 1);
		} else {
			if ('a' <= hex_digit && hex_digit <= 'f') {
				res += (hex_digit - 'a' + 10) * pow(HEX_BASE, size - i - 1);
			} else if ('A' <= hex_digit && hex_digit <= 'F') {
				res += (hex_digit - 'A' + 10) * pow(HEX_BASE, size - i - 1);
			}
		}
	}

	return res;
}

