/*
Here the Dijkstra too many times will be so slow so we need to optimize it.
You can see that in Floyd Warshall algorithm you compute All Pairs Shortest Path and that's what we need.
But we don't want to compute it blindly and give the answer because each query has a specific value called w.
You need to answer the shortest path between two vertices that doesn't pass between any city i with ri greater than w.
When you are computing the original Floyd Warshall algorithm you compute first passing from city 0, then for city 1, then
for city 2 and so on (this is the most extern loop often the k variable is used). To answer the queries for this problem
we need to transform this indexes of the cities in the ri values so we will compute for the lower ri values to the higher
ones. Therefore you can sort the ri values and then adjust the indexes in the matrix to be sorted from ri instead of the
index itself. Then you can sort the queries by w value too and then you can answer the queries while you're applying the
Floyd Warshall algorithm. You just keep applying the Floyd Warshall while the current ri value is less than or equal 
to the current w value of the query. Since you sorted the queries by w and the vertices by ri you'll get the right answer.
*/

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
#define MAXN 210
#define LOGMAXN 20
#define INF 1e9
#define EPS 1e-9
 
int adj[MAXN][MAXN];
int memo[MAXN][MAXN];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    FOR(t, 1, T+1)
    {
        printf("Case #%d:\n", t);
        int n, Q;
        map<int, int> mm;
        cin >> n >> Q;
        vii v(n);
        FOR(i, 0, n)
        {
            cin >> v[i].fst;
            v[i].snd = i;
        }
        sort(all(v));
        FOR(i, 0, n)
            FOR(j, 0, n)
                cin >> adj[i][j];
        FOR(i, 0, n)
        {
            mm[v[i].snd] = i;
            FOR(j, 0, n)
            {
                memo[i][j] = adj[v[i].snd][v[j].snd];
            }
        }
        int nq = 0; // query number
        vector<pair<ii, ii>> q(Q);
        FOR(i, 0, Q)
        {
            cin >> q[i].snd.fst >> q[i].snd.snd >> q[i].fst.fst;
            q[i].snd.fst--;
            q[i].snd.snd--;
            q[i].fst.snd = i;
        }
        sort(all(q));
        int ans[Q];
        int k = 0;
        do
        {
            while(k < n && v[k].fst <= q[nq].fst.fst)
            {
                FOR(i, 0, n)
                    FOR(j, 0, n)
                        memo[i][j] = min(memo[i][j], memo[i][k] + memo[k][j]);
                k++;
            }
            ans[q[nq].fst.snd] = memo[mm[q[nq].snd.fst]][mm[q[nq].snd.snd]];
            nq++;
        } while(nq < Q);
        FOR(i, 0, Q)
            printf("%d\n", ans[i]);
    }
    return 0;
}
close