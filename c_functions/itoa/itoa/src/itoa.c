// itoa function
// converts int(!) number to it's string representation. Max string size is 11 for INT_MIN = -2 ** 31

void itoa(int n, char *s)
{
	long sign;
	long num = n;       // if n is -2 ** 31, we're converting num to -n = 2 ** 31 that is more the MAX_INT. So num is long
	if ((sign = n) < 0) {
		num = n;     		
		if (num < 0)   // making num positive in case n was negative
			num = -num;
	}
		
	int i = 0;
	do {
		s[i++] = num % 10 + '0';
	} while ((num /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
		
	int len = i;
	int j;
	for (i = 0, j = len - 1; i <= j; ++i, --j) 
	{
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

