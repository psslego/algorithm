#include <stdio.h>
#include <stdlib.h>

typedef struct meeting { //meeting구조체 정의
	int start;
	int finish;
	int weight;
}meeting; //done

struct meeting *meetingBoard;

int compare_finish(const void* v1, const void* v2) //비교하는 함수
{
	const meeting *m1 = (const meeting*)v1;
	const meeting *m2 = (const meeting*)v2;
	return m1->finish - m2->finish;
} //done

int binary_search(meeting meetingBoard[], int idx) {
	int first = 0, last = idx - 1;

	while (first <= last) {
		int mid = (first + last) / 2;
		if (meetingBoard[mid].finish <= meetingBoard[idx].start) {
			if (meetingBoard[mid + 1].finish <= meetingBoard[idx].start)
				first = mid + 1;
			else
				return mid;
		}
		else
			last = mid - 1;
	}
	return  -1;
}


int main()
{
	//meetingBoard는 meeting구조체를 가리킨다.
	int n, tmp;
	scanf("%d", &n);
	meetingBoard = (struct meeting*)malloc(sizeof(struct meeting)*n); //size n만큼의 동적배열을 meetingBoard에 할당

	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &meetingBoard[i].start, &meetingBoard[i].finish, &meetingBoard[i].weight); //done

	//수행시간 O(nlogn)
	qsort(meetingBoard, n, sizeof(meeting), compare_finish);//끝나는 시간 기준으로 오른차순으로 정렬 done.

	int *OPT, *P;
	int mid, index, complete;
	OPT = (int*)malloc(sizeof(int)*(n + 1)); //OPT배열은 (n+1)만큼 동적할당한다.
	P = (int*)malloc(sizeof(int)*(n + 1)); //P배열 크기는 (n+1)
	P[0] = 0;
	for (int i = 1; i <= n; i++) { //수행시간 O(nlogn)
		P[i] = binary_search(meetingBoard, i - 1) + 1;
	}
	OPT[0] = 0;
	for (int i = 1; i <= n; i++) { //수행시간 O(n)
		OPT[i] = OPT[i - 1];
		if (OPT[i - 1] > meetingBoard[i - 1].weight + OPT[P[i]]) //자신을 포함하지 않고 그 전의 OPT를 선택할때
			OPT[i] = OPT[i - 1];
		else //자기자신을 포함했을 때
			OPT[i] = meetingBoard[i - 1].weight + OPT[P[i]];
		//complete = 1;
	}
	printf("%d", OPT[n]);
}