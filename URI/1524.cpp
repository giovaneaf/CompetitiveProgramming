#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF)
	{
		int ant = 0;
		vector<int> gap(n-1);
		for(int i = 0; i < n-1; ++i)
		{
			int pos;
			scanf("%d", &pos);
			gap[i] = pos - ant;
			ant = pos;
		}
		sort(gap.begin(), gap.end());
		int ans = 0;
		for(int i = 0; i < n-k; ++i)
		{
			ans += gap[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}