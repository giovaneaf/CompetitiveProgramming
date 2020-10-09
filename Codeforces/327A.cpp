#include <cstdio>
 
int main()
{
	int N;
	scanf("%d", &N);
	int val, extra, maxextra;
	val = extra = 0;
	maxextra = -1;
	for(int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		if(a)
		{
			val++;
			if(extra > 0)
				extra--;
		}
		else
		{
			extra++;
			if(maxextra < extra)
				maxextra = extra;
		}
	}
	printf("%d\n", maxextra + val);
	return 0;
}