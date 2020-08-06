#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 50010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n;
bool mark[MAXN];
set<ii> seen;
int visited[MAXN];
 
struct edge
{
    int to, c;
    edge(int to = 0, int c = 0) : to(to), c(c) {}
    bool operator< (const edge& e)
    {
        return c < e.c;
    }
};
 
void DFS(int cur, vector<edge>* adj, int p)
{
	stack<ii> s;
	s.push(mp(cur, p));
	while(s.size())
	{
		cur = s.top().first;
		p = s.top().second;
		visited[cur]++;
		s.pop();
		mark[cur] = true;
		for(edge e:adj[cur])
		{
			if((p == e.to) || seen.find(mp(cur, e.to)) != seen.end()) continue;
			seen.insert(mp(cur, e.to));
			s.push(mp(e.to, cur));	
		}
	}
    return ;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        vector<edge> adj[n];
        mark[n-1] = false;
		visited[n-1] = 0;
        FOR(i, 0, n-1)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            adj[a].emplace_back(edge(b, c));
            adj[b].emplace_back(edge(a, c));
            mark[i] = false;
			visited[i] = 0;
        }
        FOR(i, 0, n)
        {
            sort(adj[i].begin(), adj[i].end());
            if(adj[i].size() > 1)
            {
                FOR(j, 0, (int) adj[i].size())
                {
					if(visited[adj[i][j].to] >= 2) continue;
                    if(j > 0 && adj[i][j].c == adj[i][j-1].c)
                    {
						if(seen.find(mp(i, adj[i][j].to)) == seen.end()) DFS(adj[i][j].to, adj, i);
                    }
                    else if((j < (int) adj[i].size() - 1) && adj[i][j].c == adj[i][j+1].c)
                    {
                        if(seen.find(mp(i, adj[i][j].to)) == seen.end()) DFS(adj[i][j].to, adj, i);
                    }
                }
            }
        }
        vi ans;
		FOR(i, 0, n)
		{
			if(!mark[i]) ans.emplace_back(i+1);
		}
        printf("%d\n", (int) ans.size());
        FOR(i, 0, (int) ans.size())
        {
            printf("%d\n", ans[i]);
        }
		seen.clear();
    }
	return 0;
}