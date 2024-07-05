/* getline function */
#include <stdio.h> // only for pintf

#define DEFAULT_SIZE 5

int get_line(char line[], long size);

int main()
{
	char line[DEFAULT_SIZE];
	get_line(line, DEFAULT_SIZE);

	printf("%s\n", line);

	return 0;
}

int get_line(char line[], long lim)
{	
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) >= 0 && c != '\n'; ++i)
	{
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}


