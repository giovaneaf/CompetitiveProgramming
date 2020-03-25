#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;

bool findMatch(int i, const vvi &graph, vi &left, vi &right, vi &seen) {
	for(int j = 0; j < m; ++j) {
		if(graph[i][j] && !seen[j]) {
			seen[j] = true;
			if(right[j] < 0 || findMatch(right[j], graph, left, right, seen)) {
				right[j] = i;
				left[i] = j;
				return true;
			}
		}
	}
	return false;
}

int BipartiteMatching(vvi& graph, vi& left, vi& right) {
	left = vi(n, -1);
	right = vi(m, -1);

	int maxFlow = 0;
	for(int i = 0; i < n; ++i) {
		vi seen(m);
		if(findMatch(i, graph, left, right, seen)) maxFlow++;
	}
	return maxFlow;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		scanf("%d", &n);
		vi left(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &left[i]);
		}
		scanf("%d", &m);
		vi right(m);
		for(int i = 0; i < m; ++i) {
			scanf("%d", &right[i]);
		}
		vvi graph(n, vi(m));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(left[i] == 0) {
					if(right[j] == 0) {
						graph[i][j] = 1;
					}
				} else if(right[j]%left[i] == 0) {
					graph[i][j] = 1;
				}
			}
		}
		printf("Case %d: %d\n", t+1, BipartiteMatching(graph, left, right));
	}
	return 0;
}