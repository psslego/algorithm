#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 100000
void merge(int A[], int first, int mid, int last) {
	int C[MAX];
	int i = first, j = mid + 1, k = first;
	while (i <= mid && j <= last) {
		if (A[i] <= A[j]) {
			C[k] = A[i];
			i++;
		}
		else {
			C[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) { //j already all used!, only i remained, j > last.
		for (int t = j; t <= last; t++) {  //first ; is initializing, no need to write down.
			C[k] = A[t];
			k++;
		}
	}
	else { //i already all used!, only j remained, i > mid.
		for (int t = i; t <= mid; t++) {
			C[k] = A[t];
			k++;
		}
	}
	for (int t = first; t <= last; t++) { //copy merged data from array C to array A 
		A[t] = C[t];
	}
}
void mergeSort(int A[], int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;
		mergeSort(A, first, mid);
		mergeSort(A, mid + 1, last);
		merge(A, first, mid, last);
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

	mergeSort(A, 0, n - 1);

	Count[0] = 1;
	int maxCnt = 0;
	int maxIndex = 0;
	int cnt = 1;
	for (int i = 0; i < last; i++) {
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