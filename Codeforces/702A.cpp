#include <stdio.h>
 
int main()
{
	int N;
	scanf("%d", &N);
	int maxLength = 1;
	int v[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	int maxCur = 1;
	for(int i = 1; i < N; i++)
	{
		if(v[i] > v[i-1])
			maxCur++;
		else
			maxCur = 1;
		if(maxLength < maxCur)
			maxLength = maxCur;
	}
	printf("%d\n", maxLength);
	return 0;
}