/*
	Find all articulation points in graph
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define FOR(a, b, c) for(int a = b; a < c; ++a)

int n, m, k;

void TarjanAP(int cur, int root, vi*adj, vb& seen, ii* vtime, int* dad, vb& ap)
{
	static int t = 0;
	seen[cur] = true;
	vtime[cur] = mp(t, t);
	t++;
	int cnt = 0;
	for(int u : adj[cur])
	{
		if(u == dad[cur]) continue;
		if(!seen[u])
		{
			cnt++;
			dad[u] = cur;
			TarjanAP(u, root, adj, seen, vtime, dad, ap);
			vtime[cur].snd = min(vtime[cur].snd, vtime[u].snd); 
			if(cur == root) continue;
		   
            if (vtime[cur].fst <= vtime[u].snd) 
               ap[cur] = true;
			else
				vtime[cur].snd = min(vtime[cur].snd, vtime[u].snd);
		}
		else
		{
			if(cur == root) continue;
			vtime[cur].snd = min(vtime[cur].snd, vtime[u].fst);
		}
	}
	if(cur == root && cnt > 1) ap[root] = true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while(cin >> n && n)
	{
		map<string, int> mm;
		vector<string> v(n);
		string s;
		vi adj[n];
		FOR(i, 0, n)
		{
			cin >> v[i];
			mm[v[i]] = i;
		}
		cin >> m;
		FOR(i, 0, m)
		{
			string s2;
			cin >> s >> s2;
			int a, b;
			a = mm[s];
			b = mm[s2];
			// build the graph with adjacency list
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		vb ap(n, false);
		vb seen(n, false);
		ii vtime[n];
		int dad[n];
		FOR(i, 0, n)
		{
			if(!seen[i])
			{
				dad[i] = -1;
				TarjanAP(i, i, adj, seen, vtime, dad, ap);
			}
		}
		vector<string> ans;
		FOR(i, 0, n)
		{
			if(ap[i]) 	// check if this point is an articulation point
			{
				ans.emplace_back(v[i]); 
			}
		}
		sort(ans.begin(), ans.end());
		if(t > 1) printf("\n");
		printf("City map #%d: %d camera(s) found\n", t++, (int) ans.size());
		FOR(i, 0, (int) ans.size())
		{
			printf("%s\n", ans[i].c_str());
		}
	}
    return 0;
}
