// merge sort implementation

/*
 * arr: array to sort
 * l: index to sort from
 * r: index to sort to
 * arr[l: r + 1] will be sorted
 * to sort the whole array: l = 0, r = n - 1, where n = len(arr)
 */
void sort_arr(int *arr, int l, int r)
{
	if (l < r) {
		int mid = l + (r - l) / 2;
		
		// sorting the left and right parts of the array
		sort_arr(arr, l, mid);
		sort_arr(arr, mid + 1, r);

		int n1 = mid - l + 1; // size of the left part
		int n2 = r - mid; // size of the right part
	
		int left[n1], right[n2];
	
		for (int i = 0; i < n1; ++i)
			left[i] = arr[l + i];

		for (int i = 0; i < n2; ++i)
			right[i] = arr[mid + i + 1];
	
		int left_index = 0;
		int right_index = 0;
		int arr_index = l;
	
		// merging 
		while (left_index < n1 && right_index < n2)
		{
			if (left[left_index] <= right[right_index]) {
				arr[arr_index] = left[left_index];
				++left_index;
			} else {
				arr[arr_index] = right[right_index];
				++right_index;
			}
			++arr_index;
		}	

		// adding nums left in left or right
		while (left_index < n1)
			arr[arr_index++] = left[left_index++];
	
		while (right_index < n2)
			arr[arr_index++] = right[right_index++];
	}	
}
