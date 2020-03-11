#include <bits/stdc++.h>
 
#define mp make_pair
 
using namespace std;
 
int c[110];
vector<pair<int, int>> adj[1010];
int cost[1010][110];
int x[1010];
int y[1010];
int li;
int B, C0, T;
 
inline int dist(int x1, int y1, int x2, int y2)
{
	return (int) ceil(sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));
}
 
int main()
{
	cin >> x[1001] >> y[1001];
	cin >> x[1002] >> y[1002];
	cin >> B;
	cin >> C0;
	cin >> T;
	for(int i = 0; i < T; ++i)
	{
		cin >> c[i];
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i] >> li;
		for(int j = 0; j < li; ++j)
		{
			int a, mj;
			cin >> a >> mj;
			mj--;
			adj[i].emplace_back(make_pair(a, c[mj]));
			adj[a].emplace_back(make_pair(i, c[mj]));
		}
		adj[1001].emplace_back(make_pair(i, C0));
		adj[i].emplace_back(make_pair(1002, C0));
	}
	adj[1001].emplace_back(make_pair(1002, C0));
	priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push(make_pair(0.0, mp(1001, 0)));
	for(int i = 0; i < 1010; ++i)
	{
		for(int j = 0; j < 110; ++j)
		{
			cost[i][j] = 1000000000;
		}
	}
	cost[1001][0] = 0;
	int ans = -1;
	while(pq.size())
	{
		pair<int, pair<int, int>> p = pq.top();
		pq.pop();
		int curB = p.second.second;
		if(p.second.first == 1002)
		{
			ans = p.first;
			break;
		}
		for(pair<int, int>& pp : adj[p.second.first])
		{
			int u = pp.first;
			int w = pp.second*dist(x[u], y[u], x[p.second.first], y[p.second.first]);
			int newB = curB + dist(x[u], y[u], x[p.second.first], y[p.second.first]);
			if(newB > B) continue;
			if(cost[u][newB] > w + cost[p.second.first][curB])
			{
				cost[u][newB] = w + cost[p.second.first][curB];
				pq.push(mp(cost[u][newB], mp(u, newB)));
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}