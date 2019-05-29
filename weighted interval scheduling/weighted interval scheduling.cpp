#include <stdio.h>
#include <stdlib.h>

typedef struct meeting { //meeting����ü ����
	int start;
	int finish;
	int weight;
}meeting; //done

struct meeting *meetingBoard;

int compare_finish(const void* v1, const void* v2) //���ϴ� �Լ�
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
	//meetingBoard�� meeting����ü�� ����Ų��.
	int n, tmp;
	scanf("%d", &n);
	meetingBoard = (struct meeting*)malloc(sizeof(struct meeting)*n); //size n��ŭ�� �����迭�� meetingBoard�� �Ҵ�

	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &meetingBoard[i].start, &meetingBoard[i].finish, &meetingBoard[i].weight); //done

	//����ð� O(nlogn)
	qsort(meetingBoard, n, sizeof(meeting), compare_finish);//������ �ð� �������� ������������ ���� done.

	int *OPT, *P;
	int mid, index, complete;
	OPT = (int*)malloc(sizeof(int)*(n + 1)); //OPT�迭�� (n+1)��ŭ �����Ҵ��Ѵ�.
	P = (int*)malloc(sizeof(int)*(n + 1)); //P�迭 ũ��� (n+1)
	P[0] = 0;
	for (int i = 1; i <= n; i++) { //����ð� O(nlogn)
		P[i] = binary_search(meetingBoard, i - 1) + 1;
	}
	OPT[0] = 0;
	for (int i = 1; i <= n; i++) { //����ð� O(n)
		OPT[i] = OPT[i - 1];
		if (OPT[i - 1] > meetingBoard[i - 1].weight + OPT[P[i]]) //�ڽ��� �������� �ʰ� �� ���� OPT�� �����Ҷ�
			OPT[i] = OPT[i - 1];
		else //�ڱ��ڽ��� �������� ��
			OPT[i] = meetingBoard[i - 1].weight + OPT[P[i]];
		//complete = 1;
	}
	printf("%d", OPT[n]);
}