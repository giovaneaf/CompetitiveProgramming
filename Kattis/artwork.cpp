#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, k, q, R, C;

int M[MAXN][MAXN];
 
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
 
int Kruskal(vi* adj) {
  int size = n;
  initSet();
  int cost = 0;
  for(int i = 0; i < (int) e.size(); ++i) {
    if(not isSameSet(e[i].a, e[i].b)) {
      unionSet(e[i].a, e[i].b);
      cost += e[i].c;
      if(--size == 1) break;
    }
  }
  return cost;
}

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> C >> R >> q)
    {
        memset(M, 0, sizeof(M));
        n = R*C;
        initSet();
        pair<ii, ii> v[q];
        FOR(i, 0, q)
        {
            cin >> v[i].fst.snd >> v[i].fst.fst >> v[i].snd.snd >> v[i].snd.fst;
            v[i].fst.snd--; v[i].fst.fst--; v[i].snd.snd--; v[i].snd.fst--;
            if(v[i].fst.snd == v[i].snd.snd)
            {
                int curc = v[i].fst.snd;
                int minr = min(v[i].fst.fst, v[i].snd.fst);
                int maxr = max(v[i].fst.fst, v[i].snd.fst);
                FOR(j, minr, maxr+1)
                {
                    M[j][curc]++;
                }
            }
            else
            {
                int curr = v[i].fst.fst;
                int minc = min(v[i].fst.snd, v[i].snd.snd);
                int maxc = max(v[i].fst.snd, v[i].snd.snd);
                FOR(j, minc, maxc+1)
                {
                    M[curr][j]++;
                }
            }
        }
        vb seen(R*C, false);
        int cc = 0;
        FOR(i, 0, R)
        {
            FOR(j, 0, C)
            {
                if(!seen[i*C+j] && M[i][j] == 0)
                {
                    cc++;
                    seen[i*C+j] = true;
                    queue<ii> q;
                    q.push(mp(i, j));
                    while(q.size())
                    {
                        ii cur = q.front();
                        q.pop();
                        FOR(k, 0, 4)
                        {
                            int nr = cur.fst + dr[k];
                            int nc = cur.snd + dc[k];
                            if(nr < 0 || nr >= R || nc < 0 || nc >= C || M[nr][nc] > 0 || seen[nr*C+nc]) continue;
                            seen[nr*C+nc] = true;
                            unionSet(cur.fst*C+cur.snd, nr*C+nc);
                            q.push(mp(nr, nc));
                        }
                    }
                }
            }
        }
        int ans[q];
        ans[q-1] = cc;
        RFOR(i, q-1, 1)
        {
            if(v[i].fst.snd == v[i].snd.snd)
            {
                int curc = v[i].fst.snd;
                int minr = min(v[i].fst.fst, v[i].snd.fst);
                int maxr = max(v[i].fst.fst, v[i].snd.fst);
                FOR(j, minr, maxr+1)
                {
                    M[j][curc]--;
                    if(M[j][curc] == 0)
                    {
                        int r = j;
                        int c = curc;
                        set<int> s;
                        FOR(k, 0, 4)
                        {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if(nr < 0 || nr >= R || nc < 0 || nc >= C || M[nr][nc] > 0) continue;
                            s.insert(findSet(nr*C+nc));
                            unionSet(r*C+c, nr*C+nc);
                        }
                        cc += (int) -s.size()+1;
                    }
                }
            }
            else
            {
                int curr = v[i].fst.fst;
                int minc = min(v[i].fst.snd, v[i].snd.snd);
                int maxc = max(v[i].fst.snd, v[i].snd.snd);
                FOR(j, minc, maxc+1)
                {
                    M[curr][j]--;
                    if(M[curr][j] == 0)
                    {
                        int r = curr;
                        int c = j;
                        set<int> s;
                        FOR(k, 0, 4)
                        {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if(nr < 0 || nr >= R || nc < 0 || nc >= C || M[nr][nc] > 0) continue;
                            s.insert(findSet(nr*C+nc));
                            unionSet(r*C+c, nr*C+nc);
                        }
                        cc += (int) -s.size()+1;
                    }
                }
            }
            ans[i-1] = cc;
        }
        FOR(i, 0, q)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
} 