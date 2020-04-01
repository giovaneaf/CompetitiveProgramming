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
ll var[25];
ll total;
char str[MAXN][11];
int v[MAXN][11];
ll sum[(1 << 16)+5];
vector<pair<ll, ll>> memo;
bool used[MAXN][20];
bool seen[(1 << 16)+5];
int len[MAXN];
int digitOn[25];
int digitOff[25];
int pon, poff;
char read[5];

inline void init(int n)
{
	fact[0] = 1LL;
	power[0] = 1LL;
	FOR(i, 1, n)
	{
		fact[i] = (fact[i-1]*i)%MOD;
		power[i] = power[i-1]*16LL;
	}
	FOR(i, 1, 17)
	{
		var[i] = (fact[i]*fact[16-i])%MOD;
	}
}

inline int toInt(char c)
{
	if(c >= '0' && c <= '9') return c - '0';
	return 10 + c - 'a';
}

string toBin(ll x)
{
	string s;
	while(x > 0)
	{
		s += (x&1) == 0 ? '0' : '1';
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}

void compute(int mask, int pos)
{
	ll ans;
	int idx;
	ans = 0LL;
	idx = 0;
	RFOR(j, len[pos]-1, 0)
	{
		if(mask & (1 << v[pos][j])) continue;
		ans = (ans + power[idx]*v[pos][j]);
		idx++;
	}
	queue<int> q;
	q.push(mask);
	seen[mask] = true;
	int newMask;
	while(q.size())
	{
		mask = q.front();
		q.pop();
		sum[mask] += ans;
		FOR(i, 0, poff)
		{
			if((mask & (1 << digitOff[i])) == 0)
			{
				newMask = mask | (1 << digitOff[i]);
				if(!seen[newMask])
				{
					seen[newMask] = true;
					q.push(newMask);
				}
			}
		}
	}
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
		total += (var[depth]*(sum[mask]%MOD))%MOD; total %= MOD;
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
	while(~scanf(" %s", &read))
	{
		n = stoi(read, NULL, 16);
		memset(used, false, sizeof(used));
		memset(sum, 0LL, sizeof(sum));
		FOR(i, 0, n)
		{			
			scanf(" %s", &str[i]);
			len[i] = strlen(str[i]);
			FOR(j, 0, len[i])
			{
				v[i][j] = toInt(str[i][j]);
				used[i][v[i][j]] = true;
			}
		}
		int mask;
		FOR(i, 0, n)
		{
			memset(seen, false, sizeof(seen));
			pon = poff = 0;
			FOR(j, 0, 16)
			{
				if(used[i][j]) digitOn[pon++] = j;
				else digitOff[poff++] = j;
			}
			compute(0, i);
			FOR(j, 1, (1 << pon))
			{
				mask = 0;
				FOR(k, 0, pon)
				{
					if(j & (1 << k))
					{						
						mask |= (1 << digitOn[k]);
					}
				}
				compute(mask, i);
			}
		}
		memo.assign((1 << 16 + 5), mp(-1LL, -1LL));
		total = 0LL;
		pair<ll, ll> ans = solve();
		printf("%llx %llx %x\n", ans.fst, ans.snd, total);
	}
	return 0;
}