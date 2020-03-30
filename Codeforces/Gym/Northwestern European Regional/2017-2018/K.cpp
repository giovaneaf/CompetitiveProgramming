#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 4100
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
 
struct player
{
	int r, id;
	bool operator< (const player& p) const
	{
		return r > p.r;
	}
};
 
int n, sz;
vector<player> st[4*MAXN];
double dp[4*MAXN][MAXN];
player v[MAXN];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	memset(dp, 0.0, sizeof(dp));
	int fst;
	cin >> fst;
	FOR(i, 0, n-1)
	{
		cin >> v[i].r;
		v[i].id = i+1;
	}
	sort(v, v+n-1);
	v[n-1].id = 0;
	v[n-1].r = fst;
	sz = log2(n);
	int toTraverse = n - (1 << sz);
	int pos = 0;
	int stpos = (1 << sz)-1;
	while(toTraverse)
	{
		st[stpos].emplace_back(v[pos]);
		st[stpos].emplace_back(v[pos+1]);
		dp[stpos][v[pos].id] = (double) v[pos].r/(v[pos].r+v[pos+1].r);
		dp[stpos][v[pos+1].id] = (double) v[pos+1].r/(v[pos].r+v[pos+1].r);
		toTraverse--;
		pos += 2;
		stpos++;
	}
	while(pos < n)
	{
		st[stpos].emplace_back(v[pos]);
		dp[stpos][v[pos].id] = (double) 1.0;
		pos++;
		stpos++;
	}
	FOR(i, 1, sz+1)
	{
		FOR(j, (1 << (sz-i))-1, (1 << (sz-i+1))-1)
		{
			int left = 2*j+1;
			int right = left+1;
			for(player pl:st[left])
			{
				double prob = 0.0;
				for(player pr:st[right])
				{
					prob += dp[right][pr.id]*((double) pl.r/(pl.r+pr.r));
				}
				dp[j][pl.id] = dp[left][pl.id]*prob;
				st[j].emplace_back(pl);
			}
			for(player pr:st[right])
			{
				double prob = 0.0;
				for(player pl:st[left])
				{
					prob += dp[left][pl.id]*((double) pr.r/(pl.r+pr.r));
				}
				dp[j][pr.id] = dp[right][pr.id]*prob;
				st[j].emplace_back(pr);
			}
		}
	}
	printf("%.9f\n", dp[0][0]);
}