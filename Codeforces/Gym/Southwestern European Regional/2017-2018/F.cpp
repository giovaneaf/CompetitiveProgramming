#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()	
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int w;
	while(cin >> w)
	{
		int n;
		cin >> n;
		ll area = 0LL;
		while(n--)
		{
			int wi, li;
			cin >> wi >> li;
			area += (long long) wi*li;
		}
		cout << area/w << '\n';
	}
	return 0;
}