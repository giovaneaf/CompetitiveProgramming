/*
The answer is 1 + (sum of all v[i] > v[i] for i going from 0 to n-1)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int v[n];
		for(int i = 0; i < n; ++i)
			cin >> v[i];
		int nOfPiles = 1;
		for(int i = 1; i < n; ++i)
		{
			if(v[i] <= v[i-1]) continue;
			nOfPiles++;
		}
		cout << nOfPiles << '\n';
	}
	return 0;	
}