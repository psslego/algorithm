#include <stdio.h>
int main()
{
	const int MAX = 150;
	int C[MAX][MAX];//이차배열을 이용한 동적계획법
	int n = 0, k = 0;
	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			if (j == 0)
				C[i][j] = 0;
			else if (i == 0)
				C[i][j] = 1;
			else if (i < j)
				C[i][j] = C[i][i];
			else //j를 포함시키지 않은 가지수와 j를 포함시키는 가지수를 더해준다. 
				C[i][j] = C[i - j][j] + C[i][j - 1];
	printf("%d", C[n][k]);
}