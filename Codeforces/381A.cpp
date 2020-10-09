#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		int v[n];
		FOR(i, 0, n) cin >> v[i];
		int s, d;
		s = d = 0;
		int l, r;
		l = 0, r = n-1;
		bool fst = true;
		while(l <= r)
		{
			if(v[l] >= v[r])
			{
				if(fst) s += v[l];
				else d += v[l];
				l++;
			}
			else
			{
				if(fst) s += v[r];
				else d += v[r];
				r--;
			}
			fst = !fst;
		}
		printf("%d %d\n", s, d);
	}
	return 0;
}