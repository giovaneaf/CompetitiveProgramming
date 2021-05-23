#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXN 5010
#define LOGMAXN 23
#define MAXM 1110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

int T;
int n, m;

struct Planet
{
	string name;
	ll x, y, z;
};

Planet v[61];
double dist[61][61];

inline double length(Planet& p1, Planet& p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) + (p1.z-p2.z)*(p1.z-p2.z));
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		FOR(t, 0, T)
		{
			printf("Case %d:\n", t+1);
			cin >> n;
			vector<Planet> v(n);
			map<string, int> mm;
			FOR(i, 0, n) 
			{
				cin >> v[i].name >> v[i].x >> v[i].y >> v[i].z;
				mm[v[i].name] = i;
			}
			FOR(i, 0, n)
			{
				FOR(j, 0, n)
				{
					if(i == j) dist[i][j] = 0.0;
					else dist[i][j] = length(v[i], v[j]);
				}
			}
			cin >> m;
			string a, b;
			FOR(i, 0, m) 
			{
				cin >> a >> b;
				dist[mm[a]][mm[b]] = 0.0;
			}
			// Floyd Warshall
			FOR(k, 0, n)
				FOR(i, 0, n)
					FOR(j, 0, n)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			cin >> m;
			FOR(i, 0, m) 
			{
				cin >> a >> b;
				printf("The distance from %s to %s is %d parsecs.\n", a.c_str(), b.c_str(), (int) (dist[mm[a]][mm[b]]+.5));
			}
		}
	}
	return 0;
}