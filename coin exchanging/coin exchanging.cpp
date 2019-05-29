#include <stdio.h>
#define CHANGEMAX 10000
#define VARIETYMAX 100

int main()
{
	int C[CHANGEMAX][VARIETYMAX] = { 0, };//이차배열을 이용한 동적계획법
	int coins[VARIETYMAX];
	int n = 0, M = 0;
	int i, j;

	scanf("%d", &n);
	for (int k = 0; k < n; k++)
		scanf("%d", &coins[k]);
	scanf("%d", &M);

	for (i = 0; i <= M; i++) {
		for (j = 0; j <= n; j++) {
			C[i][j] = 10000;
		}
	}
	for (j = 0; j <= n; j++)
		C[0][j] = 0;
	for (i = 0; i <= M; i++) {
		for (j = 1; j <= n; j++) {
			if (i < coins[j - 1])
				C[i][j] = C[i][j - 1];
			else if (C[i - coins[j - 1]][j] + 1 < C[i][j - 1])
				C[i][j] = C[i - coins[j - 1]][j] + 1;
			else
				C[i][j] = C[i][j - 1];
		}
	}
	if (C[M][n] >= 10000)
		printf("%d", -1);
	else
		printf("%d", C[M][n]);
}