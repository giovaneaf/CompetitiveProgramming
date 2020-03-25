#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> v(n);
		int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i];
			sum += v[i];
		}
		if(sum % n > 0)
			printf("-1\n");
		else
		{
			int avg = sum/n;
			int ans = 0;
			for(int i = 0; v[i] < avg; ++i)
			{
				ans += avg - v[i];
			}
			cout << ans + 1 << "\n";
		}
	}
	return 0;
}