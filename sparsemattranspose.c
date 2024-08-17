#include <stdio.h>
void main()
{
int a[100][100], b[100][100];
int m, n;
printf("Enter size of the array : ");
scanf("%d %d", &m, &n);
for (int i = 0; i < m; i++)
{
	for (int j = 0; j < n; j++)
	{
		printf("Enter element [%d %d]: ", i, j);
		scanf("%d", &a[i][j]);
	}
}
for (int i = 0; i < m; i++)
{
	for (int j = 0; j < n; j++)
	{
		printf(" %d ", a[i][j]);
	}
	printf("\n");
}
b[0][0] = m;
b[0][1] = n;
b[0][2] = 0;
int c = 1;
for (int i = 0; i < m; i++)
{
	for (int j = 0; j < n; j++)
	{
		if (a[i][j] != 0)
		{
			b[c][0] = i;
			b[c][1] = j;
			b[c][2] = a[i][j];
			c = c + 1;
		}
	}
}
int T[100][100];
b[0][2] = c-1;
printf("\nSparse\n");
for (int i = 0; i < c; i++)
{
	for (int j = 0; j < 3; j++)
	{
		printf(" %d ", b[i][j]);
		T[j][i] = b[i][j];
	}
	printf("\n");	
}
printf("\nTranspose\n");
for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < c; j++)
	{
		printf(" %d ", T[i][j]);
	}
	printf("\n");	
}
}
