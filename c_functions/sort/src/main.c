#include <stdio.h>
#include "arr/sort_arr.h"
#include "string/sort_str.h"

int main()
{
	printf("Sorting an integer array...\n");
	int arr[] = { 5, 6, 1, 2, 3, 4, 9, 7, 8 };
	int n1 = sizeof(arr) / sizeof(arr[0]);

	sort_arr(arr, 0, n1 - 1);
	
	for (int i = 0; i < n1; ++i)
		printf("%d ", arr[i]);

	printf("\n\n");

	char s[] = "gdasdgag";
	int n2;
	for (n2 = 0; s[n2] != '\0'; ++n2);

	printf("Sorting a '%s' string...\n", s);
	sort_str(s, 0, n2 - 1);
	printf("%s\n", s);

	return 0;
}

