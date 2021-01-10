#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int hanoi_tower(int plate_num, int start, int via, int end) {
	if (plate_num == 1)
		printf("%d %d\n", start, end);
	else {
		hanoi_tower(plate_num - 1, start, end, via);
		printf("%d %d\n", start, end);
		hanoi_tower(plate_num - 1, via, start, end);
	}
}

int hanoi_tower_main() {
	int num;

	printf("원판의 개수를 입력하세요 : ");
	scanf("%d", &num);

	hanoi_tower(num, 1, 2, 3);

}

int Recursive_Binary_Search(int arr[], int start, int end, int target)
{
	int pivot;

	pivot = (start + end) / 2;

	if (start > end)
		return -1;

	if (arr[pivot] == target)
		return pivot;
	else if (arr[pivot] > target)
		return Recursive_Binary_Search(arr, 0, pivot - 1, target);
	else
		return Recursive_Binary_Search(arr, pivot + 1, end, target);

}

int Recursive_Binary_Search_main() {
	int arr[] = { 1,2,3,7,9,12,21,23,27,30 };
	int idx, len;

	len = sizeof(arr) / 4;

	idx = Recursive_Binary_Search(arr, 0, len, 3);
	printf("idx : %d\n", idx);
}

int Fibo(int n) {

	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int Recursive_Fibonacci() {
	int i;

	for (i = 1; i < 15; i++)
		printf("%d ", Fibo(i));
}

int Factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Factorial(n - 1);
}

int Recursive_Factorial() {
	
	printf("1! = %d \n", Factorial(1));
	printf("2! = %d \n", Factorial(2));
	printf("3! = %d \n", Factorial(3));
	printf("5! = %d \n", Factorial(5));
	printf("9! = %d \n", Factorial(9));
}

