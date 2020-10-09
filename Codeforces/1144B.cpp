#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 100010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

bool solve(int lr, int hr, int lc, int hc, int tgt, string* s)
{
	int sum = 0;
	FOR(i, lr, hr)
	{
		FOR(j, lc, hc)
		{
			if(s[i][j] == '@') sum++;
		}
	}
	return sum == tgt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int e, o, d;
	e = o = 0;
	vector<int> even;
	vector<int> odd;
	FOR(i, 0, n)
	{
		int a;
		cin >> a;
		if((a&1) > 0) 
		{
			odd.push_back(a);
			o++;
		}
		else
		{
			even.push_back(a);
			e++;
		}
	}
	sort(odd.begin(), odd.end(), greater<int>());
	sort(even.begin(), even.end(), greater<int>());
	ll sum = 0;
	if(o > e)
	{
		FOR(i, e+1, o)
		{
			sum += odd[i];
		}
	}
	else
	{
		FOR(i, o+1, e)
		{
			sum += even[i];
		}
	}
	printf("%lld\n", sum);
	return 0;
}