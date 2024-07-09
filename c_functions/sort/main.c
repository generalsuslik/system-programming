#include <stdio.h>
#include "sort_arr.h"

int main()
{
	int arr[] = { 5, 6, 1, 2, 3, 4, 9, 7, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort_arr(arr, 0, n - 1);
	
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}

