#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, k;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while(cin >> n >> m)
	{
		int M[110][110];
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				if(i == j) M[i][j] = 0;
				else M[i][j] = INF;
			}
		}
		FOR(i, 0, m)
		{
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			if(M[a][b] > c)
				M[a][b] = c;
		}
		int q;
		cin >> q;
		vector<pair<ii, ii>> query(q);
		FOR(i, 0, q)
		{
			cin >> query[i].snd.fst >> query[i].snd.snd >> query[i].fst.fst;
			query[i].snd.fst--, query[i].snd.snd--;
			query[i].fst.snd = i;
		}
		sort(query.begin(), query.end());
		int ans[q];
		int i = 0;
		int k = 0;
		while(i < q)
		{
			while(i < q && query[i].fst.fst == k)
			{
				ans[query[i].fst.snd] = M[query[i].snd.fst][query[i].snd.snd] == INF ? -1 : M[query[i].snd.fst][query[i].snd.snd];
				i++;
			}
			FOR(a, 0, n)
			{
				FOR(b, 0, n)
				{
					if(M[a][k] < INF && M[k][b] < INF) M[a][b] = min(M[a][b], M[a][k] + M[k][b]);
				}
			}
			k++;
		}
		printf("Instancia %d\n", t++);
		FOR(i, 0, q)
		{
			printf("%d\n", ans[i]);
		}
		putchar('\n');
	}
    return 0;
}