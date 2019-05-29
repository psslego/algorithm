#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int **adjMatrix, int visited[], int num)
{
	visited[v] = num;

	for (int w = 0; w < n; w++) {
		if (adjMatrix[v][w] == 1 && visited[w] == 0)
			dfs(w, n, adjMatrix, visited, num);
	}
}

int main()
{
	int n, m, v, w;
	int num = 0;
	int **adjMatrix, *visited;
	scanf("%d %d", &n, &m);
	adjMatrix = (int **)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		adjMatrix[i] = (int*)malloc(sizeof(int)*n);

	visited = (int *)malloc(sizeof(int)*n); //방문했는지 안했는지 배열


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			adjMatrix[i][j] = 0;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v, &w);
		adjMatrix[v][w] = 1;
		adjMatrix[w][v] = 1;
	}

	for (int i = 0; i < n; i++)
		visited[i] = 0;


	for (int v = 0; v < n; v++) {
		if (visited[v] == 0) {
			num++;
			dfs(v, n, adjMatrix, visited, num);
		}
	}

	printf("%d\n", num - 1);

	return 0;
}