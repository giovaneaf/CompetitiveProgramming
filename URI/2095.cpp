#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> q(n);
	vector<int> nlog(n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &q[i]);
	}
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &nlog[i]);
	}
	sort(q.begin(), q.end());
	sort(nlog.begin(), nlog.end());
	int j = 0;
	int cnt = 0;
	for(int i = 0; i < n and j < n; ++i)
	{
		while(j < n and q[i] >= nlog[j]) j++;
		if(j < n)
		{
			cnt++;
			j++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}