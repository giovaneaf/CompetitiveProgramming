#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	printf("%d", v[n-1]);
	for(int i = n-2; i >= 0; --i)
	{
		if((v[i] == v[i+1]) || ((v[n-1]%v[i]) > 0))
		{
			printf(" %d\n", v[i]);
			break;
		}
	}
	return 0;
}