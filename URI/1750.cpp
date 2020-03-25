#include <bits/stdc++.h>

using namespace std;

int cost(int i, int j)
{
	int absol = abs(i-j);
	return min(absol, 24 - absol);
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int minCost = 1000000000;
	for(int start = 0; start < n; ++start)
	{
		int curCost = 0;
		for(int i = 0; i < n; i += 2)
		{
            int index = (i+start)%n;
			curCost += cost(v[index], v[(index+1)%n]);
		}
		minCost = min(minCost, curCost);
	}
	printf("%d\n", minCost);
	return 0;
}