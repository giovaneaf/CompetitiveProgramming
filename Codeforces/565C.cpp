#include <cstdio>
 
int main()
{
	int N;
	scanf("%d", &N);
	int x[N];
	int h[N];
	for(int i = 0; i < N; i++)
		scanf("%d %d", &x[i], &h[i]);
	int trees = 1;
	for(int i = 1; i < N-1; i++)
	{
		if(x[i-1] < x[i]-h[i])
		{
			trees++;
		}
		else if(x[i+1] > x[i]+h[i])
		{
			x[i] = x[i]+h[i];
			trees++;
		}
	}
	if(N > 1)
		trees++;
	printf("%d\n", trees);
	return 0;
}