#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
ll mod = 1000000007LL;
int v[3];
int aux[3];
int s[3];
int c[MAXN];
int n;

bool can(int ms)
{
	FOR(i, 0, 3) aux[i] = v[i];
	bool can;
	FOR(i, 0, n)
	{
		can = false;
		FOR(j, 0, 3)
		{
			FOR(k, 0, 3)
			{
				if(c[i]*(s[j]+s[k]) >= ms)
				{
					aux[j]--; aux[k]--;
					if(aux[j] < 0 || aux[k] < 0)
					{
						aux[j]++; aux[k]++;
						continue;
					}
					can = true;
					break;
				}
			}
			if(can) break;
		}
		if(!can) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> v[0] >> v[1] >> v[2])
	{
		FOR(i, 0, 3) cin >> s[i];
		n = (v[0]+v[1]+v[2])/2;
		FOR(i, 0, n) cin >> c[i];
		sort(c, c+n);
		int l, h, mid;
		l = 2; h = 200000000;
		while(h - l > 1)
		{
			mid = l + (h-l)/2;
			if(can(mid)) l = mid;
			else h = mid-1;
		}
		printf("%d\n", can(h) ? h : l);
	}
	return 0;
}
