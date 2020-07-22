#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 110
#define MAXK 10
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
 
struct point
{
	int x, y;
	point(int x = 0, int y = 0) : x(x), y(y) {}
	double dist(point& p)
	{
		return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
	}
};
 
int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	while(cin >> n >> k)
	{
		point p[MAXN];
		for(int i = 0; i < k; ++i)
			cin >> p[i].x >> p[i].y;
		double cost[MAXN][MAXN];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				cost[i][j] = (i == j ? 0.0 : INF);
		for(int j = k; j < n; ++j)
		{
			cin >> p[j].x >> p[j].y;
			for(int i = 0; i < k; ++i)
			{
				cost[i][j] = cost[j][i] = p[j].dist(p[i]);
			}
		}
		for(int i = k; i < n; ++i)
			for(int j = i+1; j < n; ++j)
				cost[i][j] = cost[j][i] = p[i].dist(p[j]);
		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			
		double minCost[MAXN][(1 << MAXK)+5];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < (1 << k); ++j)
				minCost[i][j] = INF;
		for(int j = 0; j < k; ++j)
			minCost[j][(1 << j)] = 0.0;
			
		for(int mask = 0; mask < (1 << k); ++mask)
		{
			for(int i = 0; i < n; ++i)
			{
				for(int ss = mask; ss > 0; ss=(ss-1)&mask)
				{
					minCost[i][mask] = min(minCost[i][mask], minCost[i][ss] + minCost[i][mask-ss]);
				}
				if(INF - minCost[i][mask] > EPS)
				{
					for(int j = k; j < n; ++j)
					{
						minCost[j][mask] = min(minCost[j][mask], minCost[i][mask]+cost[j][i]);
					}
				}
			}
		}
		double ans = INF;
		for(int i = 0; i < n; ++i)
			ans = min(ans, minCost[i][(1 << k)-1]);
		printf("%.5f\n", ans);
	}
    return 0;
}