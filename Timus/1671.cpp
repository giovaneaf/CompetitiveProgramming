/*
You can think this problem in reverse order, so you start with a graph containing only the threads already done.
Then you start with some number of connected components given by the start graph, you can keep it by checking if
edge add a cycle to the graph, if it does then the number of connected components keeps the same and it's decremented
by one otherwise. Then you just go from last to first web and add each one updating the number of connected components
in the same way as described above and store the answer in a vector.
Then answer the queries in order.
You can use Disjoint Set Union(DSU) data structure (DS) a.k.a. as Union Find DS to check if adding an edge to the
graph creates a cycle.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define MAXM 100010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, k;
 
struct Edge {
  int a, b, c;
  Edge(int a, int b, int c) : a(a), b(b), c(c) {}
  bool operator< (const struct Edge& e) const {
    return c < e.c;
  }
};
 
vector<Edge> e;
vector<int> pset;
 
void initSet() {
  pset.assign(n, 0);
  for(int i = 0; i < n; ++i) pset[i] = i;
}
 
int findSet(int i) {
  return pset[i] == i ? i : (pset[i] = findSet(pset[i]));
}
 
bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}
 
 
void unionSet(int i, int j) {
  if(isSameSet(i, j)) return;
  pset[findSet(i)] = findSet(j);
}
 
int Kruskal() {
  int size = n;
  initSet();
  int ans = 0;
  for(int i = 0; i < (int) e.size(); ++i) {
    if(not isSameSet(e[i].a, e[i].b)) {
      unionSet(e[i].a, e[i].b);
	  ans += e[i].c;
      if(--size == 1) break;
    }
  }
  return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> m)
	{
		bool used[MAXM];
		FOR(i, 0, m)
		{
			int a, b, c;
			cin >> a >> b;
			a--, b--;
			e.emplace_back(Edge(a, b, 0));
			used[i] = true;
		}
		int q;
		cin >> q;
		int v[q];
		FOR(i, 0, q)
		{
			int val;
			cin >> val;
			val--;
			v[i] = val;
			used[val] = false;
		}
		initSet();
		int sz = n;
		FOR(i, 0, m)
		{
			if(used[i])
			{
				if(!isSameSet(e[i].a, e[i].b))
				{
					unionSet(e[i].a, e[i].b);
					sz--;
				}
			}
		}
		int ans[q];
		ans[q-1] = sz;
		RFOR(j, q-1, 1)
		{
			int i = v[j];
			if(!isSameSet(e[i].a, e[i].b))
			{
				unionSet(e[i].a, e[i].b);
				sz--;
			}
			ans[j-1] = sz;
		}
		FOR(i, 0, q)
		{
			if(i > 0) putchar(' ');
			printf("%d", ans[i]);
		}
		putchar('\n');
		e.clear();
	}
	return 0;
} 