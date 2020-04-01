/*
Got TLE on this in URI... I don't know why. I think time limit is so small.
Tried to implement in O((2^b)*n*|s|) where:
b is the base (always 16)
n is the number of strings given (max is 63)
|s| is the length of the biggest string (max is 9)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAXN 110
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int n, k;
ll fact[25];
ll power[25];
ll total;
char str[MAXN][11];
int v[MAXN][11];
ll sum[(1 << 16)+5];
vector<pair<ll, ll>> memo;
bool used[25];
int len[MAXN];

inline void init(int n)
{
	fact[0] = 1LL;
	power[0] = 1LL;
	FOR(i, 1, n)
	{
		fact[i] = (fact[i-1]*i)%MOD;
		power[i] = power[i-1]*16LL;
	}
}

inline int toInt(char c)
{
	if(c >= '0' && c <= '9') return c - '0';
	return 10 + c - 'a';
}

inline ll compute(int mask)
{
	FOR(i, 0, 16)
	{
		if(mask & (1 << i)) used[i] = true;
		else used[i] = false;
	}
	ll ans;
	int idx;
	ans = 0LL;
	FOR(i, 0, n)
	{
		idx = 0;
		RFOR(j, len[i]-1, 0)
		{
			if(used[v[i][j]]) continue;
			ans = (ans + power[idx]*v[i][j]);
			idx++;
		}
	}
	return ans;
}

pair<ll, ll> solve()
{
	int mask, depth, newMask;
	queue<ii> q;
	FOR(i, 0, 16)
	{
		mask = 1 << i;
		q.push(mp(mask, 1));
		memo[mask] = mp(0LL, 0LL);
	}
	while(q.size())
	{
		mask = q.front().fst; depth = q.front().snd;
		q.pop();
		total += (((fact[depth]*fact[16-depth])%MOD)*(sum[mask]%MOD))%MOD; total %= MOD;
		memo[mask].fst += sum[mask]; memo[mask].snd += sum[mask];
		FOR(j, 0, 16)
		{
			if((mask & (1 << j)) == 0)
			{
				newMask = mask | (1 << j);
				if(memo[newMask].fst == -1LL)
				{
					q.push(mp(newMask, depth+1));
					memo[newMask].fst = memo[mask].fst;
					memo[newMask].snd = memo[mask].snd;
				}
				else
				{
					if(memo[newMask].fst > memo[mask].fst)
						memo[newMask].fst = memo[mask].fst;
					if(memo[newMask].snd < memo[mask].snd)
						memo[newMask].snd = memo[mask].snd;
				}
			}
		}
		
	}
	return memo[(1 << 16)-1];
}

int main()
{
	init(20);
	while(~scanf("%d", &n))
	{
		FOR(i, 0, n)
		{			
			scanf(" %s", &str[i]);
			len[i] = strlen(str[i]);
			FOR(j, 0, len[i])
				v[i][j] = toInt(str[i][j]);
		}
		FOR(i, 1, (1 << 16))
		{
			sum[i] = compute(i);
		}
		memo.assign((1 << 16 + 5), mp(-1LL, -1LL));
		total = 0LL;
		pair<ll, ll> ans = solve();
		printf("%llx %llx %x\n", ans.fst, ans.snd, total);
	}
	return 0;
}