#include <bits/stdc++.h>

using namespace std;

int node;

int DFS(int cur, vector<bool>& visited, vector<vector<int>>& v) {
	visited[cur] = true;
	int nodes = 1;
	for(int i = 0; i < v[cur].size(); ++i) {
		int u = v[cur][i];
		if(!visited[u]) {
			nodes += DFS(u, visited, v);
		}
	}
	return nodes;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &node);
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<int>> v(n);
		for(int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		vector<bool> visited;
		visited.assign(n, false);
		visited[node] = true;
		int ans = 0;
		for(int i = 0; i < v[node].size(); ++i) {
			int u = v[node][i];
			if(!visited[u]) {
				ans += 2*DFS(u, visited, v);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}