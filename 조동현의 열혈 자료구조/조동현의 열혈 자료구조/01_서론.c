#include <stdio.h>
#include <string.h>

int Binary_Search(int arr[], int start, int end, int target) {
	
	/*  이진 탐색은 정렬된 데이터에서 쓸 수 있음
	* 주어진 데이터 모임의 중간 값과 비교해서 대소에 따라 반을 나누고
	* 이 과정을 반복하며 target을 찾는 방법임*/

	/* 이 방법으로 찾으면 O(log n)이 됨 = 밑이 2인 로그*/
	
	/*깔끔하게 짜는 법!
	 * 1. start와 end는 배열의 시작 인덱스와 마지막 인덱스이다
	 * 2. pivot은 (start + end) / 2 
	 * 3. target과 arr[pivot]의 대소에 따라 start, end 값을 조정하면 됨*/
	int pivot;

	while (start <= end) {
		pivot = (start + end) / 2;

		if (arr[pivot] == target)
			return pivot;
		else if (arr[pivot] < target)
			start = pivot + 1;
		else
			end = pivot - 1;

		/*초반엔 이렇게 했었는데 start > end 이런 식으로 해야 첫번째 인덱스를 찾을 수 있음*/
		//if (start >= end)
		//	return -1
	}
	return -1;
}

int Binary_Search_ver2(int arr[], int start, int end, int target) {

	/*pivot 값을 변경안하는 방법으로 테스트 해봄*/
	/* start <= pivot <= end 이기 때문에 start와 end에 pivot 값을 그대로 주게되면 
	 *  start = 2, end = 3인 경우 pivot은 항상 2가되고 경우에 따라 무한루프에 빠지게 됨
	 * 대표적으로 이 코드에 target에 3을 넣어보면 무한루프에 빠짐
	 * +start <= end 조건에서 부등호를 빼도 무한루프에 빠질 수 있음*/

	int pivot;

	while (start < end) {
		pivot = (start + end) / 2;

		if (arr[pivot] == target)
			return pivot;
		else if (arr[pivot] < target)
			start = pivot;
		else
			end = pivot;

		//if (start >= end)
		//	return -1;
	}
	return -1;
}

int Binary_Search_main() {

	int arr[] = { 1,2,3,7,9,12,21,23,27,30 };
	int idx;
	int i, len;
	
	len = sizeof(arr) / 4;

	for (i = 0; i < len; i++) {
		idx = Binary_Search(arr, 0, len - 1, i);
		printf("idx : %d\n", idx);
	}

	printf("\n");
	
	for (i = 0; i < len; i++) {
		idx = Binary_Search_ver2(arr, 0, len - 1, i);
		printf("idx : %d\n", idx);
	}
}

int Linear_Search(int arr[], int len, int target)
{
	/*  선형 탐색은 앞에서부터 차례대로 target을 찾는 방법임
	 * 정확하게는 앞에서라기 보단 말 그대로 선형 즉 순차적으로 target을 찾는 것*/

	/* 이 방법으로 찾으면 O(n)이 됨*/

	int i;
	for (i = 0; i < len; i++)
		if (arr[i] == target)
			return i;
	return -1;
}

int Linear_Search_main() {

	int arr[] = { 3,5,2,4,9 };
	int idx;

	idx = Linear_Search(arr, 5, 3);

	if (idx != -1)
		printf("target의 위치 : %d\n", idx);
	else
		printf("타겟을 찾지 못했습니다.\n");

}