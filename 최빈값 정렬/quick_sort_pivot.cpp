#include <stdio.h>
#define MAX 100000
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int A[], int first, int last) {
	int mid = (first + last) / 2;
	int pivot;
	//among A[first], A[mid], A[last], pivot is middle number
	//if ((pivot < A[mid] < A[last]) or (A[last] < A[mid] < pivot)) {
	//	pivot = A[mid];
	//}
	if (A[first] <= A[mid] < A[last])
		pivot = A[mid];
	else if (A[last] <= A[mid] < A[first])
		pivot = A[mid];
	else if (A[mid] <= A[first] < A[last])
		pivot = A[first];
	else if (A[last] <= A[first] < A[mid])
		pivot = A[first];
	else
		pivot = A[last];
	int left = first;
	int right = last;

	while (left <= right) {
		while (A[left] < pivot)
			left++;
		while (A[right] > pivot)
			right--;
		if (left <= right) {
			if (left != right) {
				swap(&A[left], &A[right]);
			}
			left++;
			right--;
		}
	}
	if (first < right) {
		quickSort(A, first, right);
	}
	if (left < last) {
		quickSort(A, left, last);
	}
}

int main()
{
	int n;
	int A[MAX];
	int C[MAX];
	int Count[MAX];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int first = 0;
	int	last = n - 1;

	quickSort(A, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}

	Count[0] = 1;
	int maxCnt = 0;
	int maxIndex = 0;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (A[i] == A[i + 1]) {
			Count[i + 1] = Count[i] + 1;
		}
		else {
			Count[i + 1] = 1;
		}
	}
	int maxNum = 0;
	for (int j = 1; j < n; j++) {
		if (maxCnt <= Count[j]) {
			maxCnt = Count[j];
			maxNum = A[j];
		}
	}
	printf("%d %d\n", maxNum, maxCnt);
	return 0;
}