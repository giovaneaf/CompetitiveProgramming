#include <stdio.h>
#include <string.h>

int main()
{
	int N, D;
	while(scanf("%d %d", &N, &D) && N)
	{
		char A[N+1];
		scanf("%s", A);
		char pilha[N+1];
		const int empty = -1;
		int top = empty;
		for(int i = 0; i < N; i++)
		{
			while(D > 0 && top != empty && A[i] > pilha[top])
				top--, D--;
			pilha[++top] = A[i];
		}
		top -= D;
		pilha[top+1] = '\0';
		printf("%s\n", pilha);
	}
	return 0;
}