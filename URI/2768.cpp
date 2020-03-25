#include <bits/stdc++.h>

#define INF 1e9
#define MAXN 100010
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
int dist[101][101];

void print(int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            printf("%d ", dist[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dist[i][j] = (i == j ? 0 : INF);
		while(m--)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--, v--;
			dist[u][v] = dist[v][u] = w;
		}
		int q;
		scanf("%d", &q);
		vector<pair<ii, ii>> query(q);
		for(int i = 0; i < q; ++i)
		{
			int a, b, k;
			scanf("%d %d %d", &a, &b, &k);
			--a, --b, --k;
			query[i] = mp(mp(k, i), mp(a, b));
		}
		sort(query.begin(), query.end());
		int idx = 0;
		int ans[q];
		for(int k = 0; k < n; ++k)
		{
			for(int i = 0; i < n; ++i)
			{
				for(int j = 0; j < n; ++j)
				{
					if(dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
			while(idx < query.size() && query[idx].first.first == k)
			{
				int u = query[idx].second.first;
				int v = query[idx].second.second;
				ans[query[idx].first.second] = (dist[u][v] == INF ? -1 : dist[u][v]);
				idx++;
			}
		}
		for(int i = 0; i < q; ++i)
		    printf("%d\n", ans[i]);
	}
	return 0;
}