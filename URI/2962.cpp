#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MAXN 1010
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

struct UnionFind
{
	vi pset;
	vi szset; // size of the set
	UnionFind(int n) 
	{
		pset.assign(n, 0);
		szset.assign(n, 1);
		FOR(i, 0, n) pset[i] = i;
	}
	int findSet(int i)
	{
		return (pset[i] == i ? i : (pset[i] = findSet(pset[i])));
	}
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j)
	{
		if(isSameSet(i, j)) return;
		szset[findSet(j)] += szset[findSet(i)];
		pset[findSet(i)] = findSet(j);
	}
};

struct sensor
{
	int x, y, r;
	sensor(int x = 0, int y = 0, int r = 0) : x(x), y(y), r(r) {}
};

int n, m, s;
sensor v[MAXN];

int dist(sensor& r1, sensor& r2)
{
	return (r1.x-r2.x)*(r1.x-r2.x) + (r1.y-r2.y)*(r1.y-r2.y);
}

int main()
{
	while(cin >> m >> n >> s)
	{
		UnionFind uf(MAXN);
		FOR(i, 0, s)
		{
			cin >> v[i].x >> v[i].y >> v[i].r;
			if(v[i].x-v[i].r <= 0)
			{
				uf.unionSet(i, 1001);
			}
			if(v[i].x+v[i].r >= m)
			{
				uf.unionSet(i, 1003);
			}
			if(v[i].y-v[i].r <= 0)
			{
				uf.unionSet(i, 1004);
			}
			if(v[i].y+v[i].r >= n)
			{
				uf.unionSet(i, 1002);
			}
		}
		FOR(i, 0, s)
		{
			FOR(j, i+1, s)
			{
				if(dist(v[i], v[j]) <= (v[i].r+v[j].r)*(v[i].r+v[j].r))
				{
					uf.unionSet(i, j);
				}
			}
		}
		bool cant = (uf.isSameSet(1001, 1004) || uf.isSameSet(1001, 1003) || uf.isSameSet(1002, 1003) || uf.isSameSet(1002, 1004));
		printf("%c\n", cant ? 'N' : 'S');		
	}
	return 0;
}