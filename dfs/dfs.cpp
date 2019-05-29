#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int cells[], int visited[])
{
	visited[v] = 1;

	if (v - cells[v] >= 0) {
		if (visited[v - cells[v]] == 0)
			dfs(v - cells[v], n, cells, visited);
	}

	if (v + cells[v] < n) {
		if (visited[v + cells[v]] == 0)
			dfs(v + cells[v], n, cells, visited);
	}
}

int main()
{
	int n;
	int max = 0;
	int maxIdx = 0;
	int startPosition = 0;
	int *cells, *visited, *num;
	scanf("%d", &n);
	cells = (int *)malloc(sizeof(int)*n); // �� �迭
	visited = (int *)malloc(sizeof(int)*n); //�湮�ߴ��� ���ߴ��� �迭
	num = (int *)malloc(sizeof(int)*n); //startPosition���� �����ִ� ������ �迭
	for (int i = 0; i < n; i++)
		scanf("%d", &cells[i]);

	while (startPosition < n) {
		for (int i = 0; i < n; i++)
			visited[i] = 0;

		dfs(startPosition, n, cells, visited);

		for (int i = 0; i < n; i++)
			if (visited[i] == 1)
				num[startPosition] ++;

		startPosition++;
	}

	for (int i = 0; i < n; i++) {
		if (max < num[i]) {
			maxIdx = i;
			max = num[i];
		}
	}

	printf("%d", maxIdx);

	return 0;
}