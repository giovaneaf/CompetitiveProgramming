#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int main()
{
	int n;
	while(cin >> n && (n > 0))
	{
		int nsqr = n*n;
		vector<int> adj[nsqr];
		for(int i = 0; i < nsqr; ++i)
		{
			bool a, b, c, d;
			cin >> a >> b >> c >> d;
			if(a)
			{
				adj[i].push_back(i-n);
			}
			if(b)
			{
				adj[i].push_back(i+n);
			}
			if(c)
			{
				adj[i].push_back(i-1);
			}
			if(d)
			{
				adj[i].push_back(i+1);
			}
		}
		int P;
		cin >> P;
		while(P--)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			int src = (n-1-y1)*n + x1;
			int dst = (n-1-y2)*n + x2;
			vector<int> dist;
			dist.assign(nsqr, INF);
			dist[src] = 0;
			queue<int> q;
			q.push(src);
			while(q.size())
			{
				int cur = q.front();
				q.pop();
				for(int i = 0; i < (int) adj[cur].size(); ++i)
				{
					int u = adj[cur][i];
					if(u < 0 || u >= nsqr || dist[u] != INF)
						continue;
					dist[u] = dist[cur] + 1;
					if(u == dst) break;
					q.push(u);
				}
			}
			if(dist[dst] == INF)
				printf("Impossible\n");
			else
				printf("%d\n", dist[dst]);
		}
		putchar('\n');
	}
	return 0;
}