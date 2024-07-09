// merge sorting a string

/*
 * s: string to sort
 * l: index to sort from
 * r: index to sort to
 * s[l: r + 1] will be sorted
 * to sort the whole string: l = 0, r = n - 1, where n = len(s)
 */
void sort_str(char *s, int l, int r)
{
	if (l < r) {
		int mid = l + (r - l) / 2;

		// sorting the left and right parts of the array
		sort_str(s, l, mid);
		sort_str(s, mid + 1, r);

		int n1 = mid - l + 1; // size of the left part
		int n2 = r - mid; // size of the right part

		int left[n1], right[n2];

		for (int i = 0; i < n1; ++i)
			left[i] = s[l + i];

		for (int i = 0; i < n2; ++i)
			right[i] = s[mid + i + 1];

		int left_index = 0;
		int right_index = 0;
		int s_index = l;

		// merging
		while (left_index < n1 && right_index < n2)
		{
			if (left[left_index] <= right[right_index]) {
				s[s_index] = left[left_index];
				++left_index;
			} else {
				s[s_index] = right[right_index];
				++right_index;
			}
			++s_index;
		}

		// adding nums left in left or right
		while (left_index < n1 && s_index < r)
			s[s_index++] = left[left_index++];

		while (right_index < n2 && s_index < r)
			s[s_index++] = right[right_index++];
	}
}


