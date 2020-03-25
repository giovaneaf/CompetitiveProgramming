#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q, k;
ii l;
ii r;

bool solve(int mask, int pos, int last, ii* v)
{
	if(pos == n)
	{
		return last == r.fst;
	}
	bool ans = false;
	FOR(i, 0, m)
	{
		if((mask & (1 << i)) > 0) continue;
		int nl = -1;
		if(last == v[i].fst)
		{
			nl = v[i].snd;
		}
		else if(last == v[i].snd)
		{
			nl = v[i].fst;
		}
		if(nl != -1)
		{
			ans = ans || solve(mask | (1 << i), pos+1, nl, v);
		}
		if(ans) return true;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n && n)
	{
		cin >> m;
		ii v[m];
		cin >> l.fst >> l.snd;
		cin >> r.fst >> r.snd;
		FOR(i, 0, m)
		{
			cin >> v[i].fst >> v[i].snd;
		}
		bool can = solve(0, 0, l.snd, v);
		printf("%s\n", can ? "YES" : "NO");
	}
    return 0;
}