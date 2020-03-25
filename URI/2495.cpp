#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	while(scanf("%d", &N) != EOF)
	{
		bool A[N];
		memset(A, true, sizeof(bool)*N);
		for(int i = 0; i < N-1; i++)
		{
			int b;
			scanf("%d", &b);
			A[b-1] = false;
		}
		for(int i = 0; i < N; i++)
			if(A[i])
			{
				printf("%d\n", i+1);
				break;
			}
	}
	return 0;
}