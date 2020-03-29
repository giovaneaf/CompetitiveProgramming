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
#define MAXN 110
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0

const double pi = atan(1)*4;

int n, m;
double r;
double rS; // radial slice
double aS; // angle slice
double radius[MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
double dist[MAXN][MAXN];

double Dijkstra(ii& s, ii& d)
{
	FOR(i, 0, m+1)
	{
		FOR(j, 0, n+1)
		{
			dist[i][j] = 1e18;
		}
	}
	priority_queue<pair<double, ii>, vector<pair<double, ii>>, greater<pair<double, ii>>> pq;
	pq.push(mp(0.0, s));
	dist[s.fst][s.snd] = 0.0;
	int nx, ny;
	while(pq.size())
	{
		ii cur = pq.top().snd;
		double curW = pq.top().fst;
		if((cur == d) || (cur.snd == 0 && d.snd == 0))
			return dist[cur.fst][cur.snd];
		pq.pop();
		if(fabs(curW - dist[cur.fst][cur.snd]) > EPS) continue;
		FOR(k, 0, 4)
		{
			nx = cur.fst + dx[k];
			ny = cur.snd + dy[k];
			if(nx < 0 || nx > m || ny < 0 || ny > n) continue;
			double w;
			if(k < 2) w = aS*radius[cur.snd];
			else w = rS;
			if(dist[nx][ny] > dist[cur.fst][cur.snd] + w)
			{
				dist[nx][ny] = dist[cur.fst][cur.snd] + w;
				pq.push(mp(dist[nx][ny], mp(nx, ny)));
			}
		}
	}
	assert(false);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> m >> n >> r)
	{
		rS = r/n;
		aS = pi/m;
		radius[0] = 0.0;
		FOR(i, 1, n+1)
		{
			radius[i] = radius[i-1] + rS;
		}
		ii s, d;
		cin >> s.fst >> s.snd >> d.fst >> d.snd;
		if(s.snd == 0 && d.snd == 0)
			printf("0\n");
		else
			printf("%.10f\n", Dijkstra(s, d));
	}
	return 0;
}