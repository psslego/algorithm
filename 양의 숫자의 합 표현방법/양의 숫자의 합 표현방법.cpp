#include <stdio.h>
int main()
{
	const int MAX = 150;
	int C[MAX][MAX];//�����迭�� �̿��� ������ȹ��
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
			else //j�� ���Խ�Ű�� ���� �������� j�� ���Խ�Ű�� �������� �����ش�. 
				C[i][j] = C[i - j][j] + C[i][j - 1];
	printf("%d", C[n][k]);
}