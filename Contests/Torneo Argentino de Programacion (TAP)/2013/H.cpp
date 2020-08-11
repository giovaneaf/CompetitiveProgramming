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
#define MAXN 1000001
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int n, m;
int memo[MAXN];
int spf[MAXN];
int acc[MAXN][12];

void Sieve()
{
	FOR(i, 0, MAXN) spf[i] = i;
	for(int i = 2; i < MAXN; i += 2) spf[i] = 2;
	for(int i = 3; i < MAXN; i += 2)
	{
		if(spf[i] == i)
		{
			for(ll j = (ll) i*i; j < MAXN; j += i)
			{
				spf[j] = min(spf[j], i);
			}
		}
	}
}

int findK(int n)
{
	if(n == spf[n]) return memo[n] = 0;
	if(memo[n] == -1)
	{
		int ans, newn, tmp, last;
		ans = newn = 0;
		tmp = n;
		while(tmp > 1)
		{
			newn += spf[tmp];
			last = spf[tmp];
			while(tmp > 1 && spf[tmp] == last) tmp /= spf[tmp];
		}
		ans = 1 + findK(newn);
		memo[n] = ans;
	}
	return memo[n];
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	Sieve();
	memset(memo, -1, sizeof(memo));
	memset(acc, 0, sizeof(acc));
	int maxK = 0;
	FOR(i, 2, MAXN)
	{
		acc[i][findK(i)]++;
	}
	FOR(i, 1, MAXN)
	{
		FOR(j, 0, 12)
		{
			acc[i][j] += acc[i-1][j];
		}
	}
	int a, b, k;
	while(cin >> n)
	{
		while(n--)
		{
			cin >> a >> b >> k;
			k--;
			if(k >= 12) printf("0\n");
			else printf("%d\n", acc[b][k] - acc[a-1][k]);
		}
	}
	return 0;
}
