#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 210000
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

typedef struct Edge Edge;

int n, m, a;

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

ii Kruskal() {
  int size = n;
  initSet();
  int sum = 0;
  sort(all(e));
  for(int i = 0; i < e.size(); ++i) {
    if(e[i].c >= a) break;
    if(not isSameSet(e[i].a, e[i].b)) {
      unionSet(e[i].a, e[i].b);
      sum += e[i].c;
      if(--size == 1) break;
    }
  }
  return {sum+size*a, size};
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    FOR(t, 0, T)
    {
        cin >> n >> m >> a;
        FOR(i, 0, m)
        {
            int a,b,c;
            cin >> a >> b >> c;
            a--, b--;
            e.emplace_back(Edge(a, b, c));
        }
        ii ans = Kruskal();
        printf("Case #%d: %d %d\n", t+1, ans.fst, ans.snd);
        e.clear();
    }
    return 0;
}
