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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

#define DEBUG 0

int n, q;

struct point
{
	ll x, y;
	bool operator< (const point& p) const
	{
		if(x != p.x) return x < p.x;
		return y > p.y;
	}
};

ll cross(const point& a, const point& b, const point& c)
{
	return (b.x-a.x)*(b.y-c.y) - (b.y-a.y)*(b.x-c.x);
}

ll cross(point& a, point& b, point& c)
{
	return (b.x-a.x)*(b.y-c.y) - (b.y-a.y)*(b.x-c.x);
}

struct seg
{
	int id;
	point p1, p2;
	bool operator< (const seg& s) const
	{
		if(p1.x < s.p1.x) return cross(p1, s.p1, p2) > 0;
		else return cross(s.p1, p1, s.p2) < 0;
	}
};

struct sweep
{
	ll x, y, e, id;
	bool operator< (const sweep& s) const
	{
		if(x != s.x) return x < s.x;
		if(e != s.e) return e < s.e;
		return y > s.y;
	}
};

seg v[MAXN];
sweep s[5*MAXN];
ii ans[MAXN];
int touch[MAXN];
int posX[MAXN];

ii solve(int cur, int x, vi& adj)
{
	if(cur == -1)
	{
		return mp(x, -1);
	}
	if(v[cur].p1.y == v[cur].p2.y)
	{
		return mp(x, v[cur].p1.y);
	}
	if(ans[cur].fst == -1)
	{
		if(v[cur].p1.y > v[cur].p2.y)
		{
			ans[cur] = solve(adj[cur], v[cur].p1.x, adj);
		}
		else
		{
			ans[cur] = solve(adj[cur], v[cur].p2.x, adj);
		}
	}
	return ans[cur];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> q)
	{
		int sz = 0;
		FOR(i, 0, n)
		{
			cin >> v[i].p1.x >> v[i].p1.y >> v[i].p2.x >> v[i].p2.y;
			if(v[i].p1.x > v[i].p2.x)
			{
				swap(v[i].p1, v[i].p2);
			}
			v[i].id = i;
			s[sz++] = {v[i].p1.x, v[i].p1.y, 0, i};
			s[sz++] = {v[i].p2.x, v[i].p2.y, 2, i};
		}
		if(DEBUG)
		{
			const int value = 400000;
			printf("datax1=[");
			for(int i = 0; i < n; i++)
			{
				if(v[i].p1.x < value)
				{
					printf("%lld", v[i].p1.x);
					if(i < n-1)
						putchar(',');
				}
			}
			printf("]\n");
			printf("datay1=[");
			for(int i = 0; i < n; i++)
			{
				if(v[i].p1.x < value)
				{
					printf("%lld", v[i].p1.y);
					if(i < n-1)
						putchar(',');
				}
			}
			printf("]\n");
			printf("datax2=[");
			for(int i = 0; i < n; i++)
			{
				if(v[i].p1.x < value)
				{
					printf("%lld", v[i].p2.x);
					if(i < n-1)
						putchar(',');
				}
			}
			printf("]\n");
			printf("datay2=[");
			for(int i = 0; i < n; i++)
			{
				if(v[i].p1.x < value)
				{
					printf("%lld", v[i].p2.y);
					if(i < n-1)
						putchar(',');
				}
			}
			printf("]\n");
		}
		int x;
		FOR(i, 0, q)
		{
			cin >> posX[i];
			s[sz++] = {posX[i], 0, 1, i};
		}
		sort(s, s+sz);
		set<seg> line;
		vi adj(n, -1);
		FOR(i, 0, sz)
		{
			if(s[i].e == 0)
			{
				seg cur = v[s[i].id];
				line.insert(cur);
				if(cur.p1.y > cur.p2.y)
				{
					auto it = line.find(cur);
					it++;
					if(it != line.end())
					{
						adj[cur.id] = (it->id);
					}
				}
			}
			else if(s[i].e == 1)
			{
				if(line.empty())
				{
					touch[s[i].id] = -1;
				}
				else
				{
					touch[s[i].id] = line.begin()->id;
				}
			}
			else
			{
				seg cur = v[s[i].id];
				if(cur.p1.y < cur.p2.y)
				{
					auto it = line.find(cur);
					it++;
					if(it != line.end())
					{
						adj[cur.id] = (it->id);
					}
				}
				line.erase(cur);
			}
		}
		FOR(i, 0, n)
		{
			ans[i] = mp(-1, -1);
		}
		FOR(i, 0, q)
		{
			if(!DEBUG)
			{
				if(touch[i] == -1)
				{
					printf("%d\n", posX[i]);
				}
				else
				{
					ii p = solve(touch[i], posX[i], adj);
					printf("%d", p.first);
					if(p.second != -1)
						printf(" %d", p.second);
					putchar('\n');
				}
			}
		}
	}
	return 0;
}

