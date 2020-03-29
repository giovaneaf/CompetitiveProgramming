#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL

int n;
vector<vector<int>> acc(MAXN, vector<int>(3, 0));
ii v[3];

int disp(int l, int r, int id)
{
	int sz;
	int eq = 0;
	if(r >= l)
	{
		sz = r-l+1;
		eq = acc[r][id] - (l > 0 ? acc[l-1][id] : 0);
	}
	else
	{
		sz = r+1 + n-l;
		eq = acc[n-1][id] - acc[l-1][id] + acc[r][id];
	}
	return sz-eq;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n)
	{
		char c;
		FOR(i, 0, n)
		{
			cin >> c;
			FOR(j, 0, 3)
			{
				acc[i][j] = ((c-'A' == j) ? 1 : 0) + (i > 0 ? acc[i-1][j] : 0);
			}
		}
		v[0] = {0, acc[n-1][0]-1};
		v[1] = {v[0].snd+1, v[0].snd + acc[n-1][1]};
		v[2] = {v[1].snd+1, v[1].snd + acc[n-1][2]};
		int ans, tmp;
		ans = n;
		FOR(k, 0, 2)
		{
			FOR(i, 0, n)
			{
				tmp = 0;
				FOR(j, 0, 3)
				{
					if(acc[n-1][j] == 0) continue;
					tmp += disp(v[j].fst, v[j].snd, j);
				}
				ans = min(ans, tmp);
				FOR(j, 0, 3)
				{
					if(acc[n-1][j] == 0) continue;
					v[j].fst++;
					v[j].snd++;
					if(v[j].fst == n) v[j].fst = 0;
					if(v[j].snd == n) v[j].snd = 0;
				}
			}
			v[0] = {0, acc[n-1][0]-1};
			v[2] = {v[0].snd+1, v[0].snd + acc[n-1][2]};
			v[1] = {v[2].snd+1, v[2].snd + acc[n-1][1]};
		}
		printf("%d\n", ans);
	}
	return 0;
}