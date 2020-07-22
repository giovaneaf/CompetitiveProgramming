/*
Because there are no two cakes entering or exiting at the same time you can
just compute all the differences for all cakes entering (they are all different for a fixed time)
You can put it on map and after that iterate over all n*m differences and get the difference
that is correct for the most amount of cakes.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n, m;
	cin >> n >> m;
	int a[2010];
	int b[2010];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int j = 0; j < m; ++j)
		cin >> b[j];
	map<int, int> mm;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(b[j] - a[i] >= 0)
				mm[b[j]-a[i]]++;
		}
	}
	int ans = 0;
	int cnt = 0;
	for(auto it = mm.begin(); it != mm.end(); ++it)
	{
		if(it->second > cnt)
		{
			cnt = it->second;
			ans = it->first;
		}
	}
	printf("%d\n", ans);
	return 0;
}