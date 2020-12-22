#include <stdio.h>

int Lsearch(int arr[], int len, int target)
{
	int i;
	for (i = 0; i < len; i++) {
		if (arr[i] == target)
			return i;
	}

	return -1;
}

int main(void)
{
	int arr[] = { 3, 5, 2, 4, 9 };
	int index;

	index = Lsearch(arr, sizeof(arr) / sizeof(int), 4);

	if (index == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d\n", index);

	return 0;
}