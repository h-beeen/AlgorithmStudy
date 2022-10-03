#include <stdio.h>

int main()
{
	int res, N, X;
	scanf("%d %d",&N, &X);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &res);
		if(res < X)
			printf("%d ", res);
	}
}