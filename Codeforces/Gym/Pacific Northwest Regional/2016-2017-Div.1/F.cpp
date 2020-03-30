// Reduced from 2-SAT problem using that if a lamp is iluminating a row then is non-negated
// and if it's iluminating a column is negated, computed all row and col intersections and 
// did converted from 2-CNF to implications
// After that runned SCC (Strong Connected Component) Kosaraju's Algorithm and
// checked if any lamp is negated and non-negated which is a contradiction 
// If it's is then the answer is NO else is YES
// Time Complexity: O(l²) - Kosaraju's Algorithm, finding all intersections

// 2-SAT here: https://www.geeksforgeeks.org/2-satisfiability-2-sat-problem/
// Kosaraju's Algorithm here: https://www.geeksforgeeks.org/strongly-connected-components/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define LOGMAXN 20
#define INF 1000000010

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

int n, r, l;

void kosaraju1(int cur, vector<bool>& visited, stack<int>& s, vi* adj)
{
	visited[cur] = true;
	for(int i = 0; i < adj[cur].size(); ++i)
	{
		int u = adj[cur][i];
		if(!visited[u])
			kosaraju1(u, visited, s, adj);
	}
	s.push(cur);
}

bool kosaraju2(vi* radj, stack<int>& s)
{
	vector<bool> visited;
	visited.assign(2*l, false);
	while(s.size())
	{
		int cur = s.top();
		s.pop();
		if(visited[cur]) continue;
		vector<int> scc;
		queue<int> q;
		q.push(cur);
		while(q.size())
		{
			cur = q.front();
			q.pop();
			scc.push_back(cur%l);
			visited[cur] = true;
			for(int i = 0; i < radj[cur].size(); ++i)
			{
				int u = radj[cur][i];
				if(!visited[u])
				{
					q.push(u);
				}
			}
		}
		sort(scc.begin(), scc.end());
		for(int i = 1; i < scc.size(); ++i)
		{
			if(scc[i] == scc[i-1])
				return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> r >> l)
	{
		map<ii, int> m;
		vi row[n];
		vi col[n];
		for(int i = 0; i < l; ++i)
		{
			int r, c;
			cin >> r >> c;
			--r, --c;
			m[{r,c}] = i;
			row[r].push_back(c);
			col[c].push_back(r);
		}
		for(int i = 0; i < n; ++i)
		{
		    sort(row[i].begin(), row[i].end());
		    sort(col[i].begin(), col[i].end());
		}
		vi adj[2*l];
		vi radj[2*l];
		for(int i = 0; i < n; ++i) // traversing rows
		{
			for(int j = 0; j < row[i].size(); ++j)
			{
				int k = j+1;
				while(k < row[i].size() && row[i][j] + r >= row[i][k])
				{
					int a = m[{i, row[i][j]}];
					int b = m[{i, row[i][k]}];
					adj[l+a].push_back(b);
					adj[l+b].push_back(a);
					radj[b].push_back(l+a);
					radj[a].push_back(l+b);
					k++;
				}
			}
		}
		for(int i = 0; i < n; ++i) // traversing cols
		{
			for(int j = 0; j < col[i].size(); ++j)
			{
				int k = j+1;
				while(k < col[i].size() && col[i][j] + r >= col[i][k])
				{
					int a = m[{col[i][j], i}];
					int b = m[{col[i][k], i}];
					adj[a].push_back(l+b);
					adj[b].push_back(l+a);
					radj[l+b].push_back(a);
					radj[l+a].push_back(b);
					k++;
				}
			}
		}
		vector<bool> visited;
		stack<int> s;
		visited.assign(2*l, false);
		for(int i = 0; i < 2*l; ++i)
		{
			if(!visited[i])
				kosaraju1(i, visited, s, adj);
		}
		cout << (kosaraju2(radj, s) ? "YES" : "NO") << "\n";
	}
	return 0;
}