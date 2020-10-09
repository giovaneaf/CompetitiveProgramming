#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define rREP(i, a, n) for(int i = a; i >= n; --i)


int main()
{
	int n, k;
	cin >> n >> k;
	vi v(n);
	REP(i, 0, n)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if(k == n)
	{
		printf("%d\n", v[k-1]);
	}
	else if(k == 0)
	{
		if(v[0] == 1)
			printf("-1\n");
		else
			printf("%d\n", v[0]-1);
	}
	else
	{
		if(v[k-1] == v[k])
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", v[k-1]);
		}
	}
	return 0;
}
