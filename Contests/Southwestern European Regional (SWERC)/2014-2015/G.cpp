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
#define MAXN 50010
#define LOGMAXN 20
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int n;
vii v;
vii v1, v2;

int prep(vii& nv)
{
	int nxt;
	int mx, my;
	set<int> sx;
	set<int> sy;
	mx = my = 0;
	FOR(i, 0, n)
	{
		nxt = (i+1 == n ? 0 : i+1);
		mx = max(mx, v[i].snd);
		my = max(my, v[i].fst);
		sx.insert(v[i].snd);
		sy.insert(v[i].fst);
	}
	nv = v;
	int sz = mx;
	FOR(i, 0, mx)
	{
		if(sx.find(i) == sx.end())
		{
			FOR(j, 0, n)
			{
				if(v[j].snd > i)
				{
					nv[j].snd--;
				}
			}
			sz--;
		}
	}
	FOR(i, 0, my)
	{
		if(sy.find(i) == sy.end())
		{
			FOR(j, 0, n)
			{
				if(v[j].fst > i)
				{
					nv[j].fst--;
				}
			}
		}
	}
	/*FOR(j, 0, n)
	{
		printf("(%d %d)\n", nv[j].snd, nv[j].fst);
	}*/
	return sz;
}

void rotate(vii& nv, int sz)
{
	FOR(i, 0, n)
	{
		nv[i] = mp(nv[i].snd, sz-nv[i].fst);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		v.resize(n);
		FOR(i, 0, n)
		{
			cin >> v[i].snd >> v[i].fst;
		}
		v1.resize(n);
		int sz = prep(v1);
		cin >> n;
		FOR(i, 0, n)
		{
			cin >> v[i].snd >> v[i].fst;
		}
		v2.resize(n);
		prep(v2);
		if((int) v1.size() != v2.size())
		{			
			printf("no\n");
			continue;
		}
		bool can = false;
		bool eq;
		FOR(i, 0, 4)
		{
			FOR(j, 0, n)
			{
				eq = true;
				FOR(k, 0, n)
				{
					if(v1[k] != v2[(j+k)%n])
					{
						eq = false;
						break;
					}
				}
				if(eq)
				{
					can = true;
					break;
				}
			}
			if(can) break;
			rotate(v1, sz);
		}
		printf("%s\n", can ? "yes" : "no");
	}
	return 0;
}
