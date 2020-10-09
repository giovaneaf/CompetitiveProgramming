#include <stdio.h>
#include <algorithm>
#include <vector>

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	std::vector<int> v(M);
	for(int i = 0; i < M; i++)
	{
		int a;
		scanf("%d", &a);
		v[i] = a;
	}
	std::sort(v.begin(), v.end());
	int ans = 100000;
	for(int i = N-1; i < M; i++)
	{
		if(ans > v[i] - v[i-(N-1)])
			ans = v[i] - v[i-(N-1)];
	}
	printf("%d\n", ans);
	return 0;
}