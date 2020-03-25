#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 35
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m;
 
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
 
void Kruskal() {
  int size = n;
  initSet();
  for(int i = 0; i < e.size(); ++i) {
    if(not isSameSet(e[i].a, e[i].b)) {
      unionSet(e[i].a, e[i].b);
	  printf("%d %d\n", e[i].a+1, e[i].b+1);
      if(--size == 1) break;
    }
  }
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		printf("Teste %d\n", t++);
		FOR(i, 0, m)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			e.emplace_back(Edge(min(a, b), max(a, b), c));
		}
		sort(e.begin(), e.end());
		Kruskal();
		e.clear();
		printf("\n");
	}
	return 0;
} 