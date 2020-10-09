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
	vector<int> v(n);
	FOR(i, 0, n)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<int> inc;
	vector<int> dec;
	inc.emplace_back(v[0]);
	FOR(i, 1, n)
	{
		if(v[i] > inc[inc.size()-1]) inc.emplace_back(v[i]);
		else dec.emplace_back(v[i]);
	}
	bool can = true;
	FOR(i, 1, dec.size())
	{
		if(dec[i] <= dec[i-1])
		{
			can = false;
			break;
		}			
	}
	if(!can)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("%d\n", (int) inc.size());
	FOR(i, 0, inc.size())
	{
		if(i > 0) printf(" ");
		printf("%d", inc[i]);
	}
	putchar('\n');
	printf("%d\n", (int) dec.size());
	RFOR(i, dec.size()-1, 0)
	{
		if(i < dec.size()-1) printf(" ");
		printf("%d", dec[i]);
	}
	putchar('\n');
	return 0;
}