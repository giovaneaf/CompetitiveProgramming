#include <cstdio>
 
int main()
{
	int N, k;
	scanf("%d %d", &N, &k);
	int v[N];
	scanf("%d", &v[0]);
	for(int i = 1; i < N; i++)
	{
		scanf("%d", &v[i]);
		v[i] += v[i-1];
	}
	int small = v[k-1];
	int index = 1;
	for(int i = k; i < N; i++)
	{
		int aux = v[i] - v[i-k];
		if(small > aux)
		{
			index = i-k+2;
			small = aux;
		}
	}
	printf("%d\n", index);
	return 0;
}