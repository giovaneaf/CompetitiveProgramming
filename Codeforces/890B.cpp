#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int v[200010] = {};
	for(int i = 1; i <= n; i++)
	{
		int ai;
		scanf("%d", &ai);
		v[ai] = i;
	}
	int minIndex = -1;
	for(int i = 0; i <= 200000; i++)
		if(v[i] > 0)
		{
			if(minIndex == -1)
				minIndex = i;
			else if(v[minIndex] > v[i])
				minIndex = i;
		}
	cout << minIndex << endl;
	return 0;
}