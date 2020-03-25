#include <stdio.h>
#include <math.h>

int main()
{
	int C, N;
	while(scanf("%d %d", &C, &N) != EOF)
	{
		int A[N];
		for(int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		int a = C/N;
		bool can = false;
		for(int i = A[0]; i < A[1]; i++)
		{
			bool possible = true;
			int pos = i;
			for(int j = 0; j < N-1; j++)
			{
				if(A[j+1] <= pos)
				{
					possible = false;
					break;
				}
				pos += a;
				if(A[j+1] > pos)
				{
					possible = false;
					break;
				}
			}
			if(A[0] + C <= pos)
				possible = false;
			else if(A[0] + C > pos + a)
				possible = false;
			if(possible)
			{
				can = true;
				break;
			}
		}
		if(can)
			printf("S");
		else
			printf("N");
		putchar('\n');
	}
	return 0;
}