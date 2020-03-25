#include <stdio.h>

int main()
{
	int N;
	while(scanf("%d", &N) && N)
	{
		int A[N];
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &A[i]);
			A[i]--;
		}
		int i = 0;
		unsigned long long int moves = 0;
		while(i < N)
		{
			if(i == A[i])
				i++;
			else
			{
				int aux = A[A[i]];
				A[A[i]] = A[i];
				A[i] = aux;
				moves += (2*(A[i] - i) - 1);
			}
		}
		if(moves%2 == 0)
			printf("Carlos\n");
		else
			printf("Marcelo\n");
	}
	return 0;
}