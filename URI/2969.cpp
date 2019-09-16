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
#define MAXN 410
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9

int n, m;
int FW[MAXN][MAXN];
int M[MAXN][MAXN];
int Temp[MAXN];
int ans[100010];
int idx[MAXN];

void compute(vector<pair<ii, ii>>& q, vii& T)
{
	FOR(i, 0, n)
	{
		idx[T[i].snd] = i;
		FOR(j, 0, n)
		{
			FW[i][j] = M[T[i].snd][T[j].snd];
		}
	}
	int sz = (int) q.size();
	int k = 0;
	int pos = 0;
	int cnt = 0;
	while(pos < sz)
	{
		while(k < n && cnt < q[pos].fst.fst)
		{
			FOR(i, 0, n)
				FOR(j, 0, n)
					if(FW[i][k] != INF && FW[k][j] != INF)
						FW[i][j] = min(FW[i][j], FW[i][k] + FW[k][j]);
			k++;
			while(k < n && T[k].fst == T[k-1].fst)
			{
				FOR(i, 0, n)
					FOR(j, 0, n)
						if(FW[i][k] != INF && FW[k][j] != INF)
							FW[i][j] = min(FW[i][j], FW[i][k] + FW[k][j]);
				k++;
			}
			cnt++;
		}
		ans[q[pos].fst.snd] = FW[idx[q[pos].snd.fst]][idx[q[pos].snd.snd]];
		pos++;
	}
}

int main()
{
	while(cin >> n >> m)
	{
		vii Tmin(n);
		vii Tmax(n);
		FOR(i, 0, n)
		{
			cin >> Temp[i];
			Tmin[i] = mp(Temp[i], i);
			Tmax[i] = mp(Temp[i], i);
		}
		sort(all(Tmin));
		sort(all(Tmax), greater<ii>());
		int a, b, c;
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				M[i][j] = (i == j ? 0 : INF);
			}
		}
		FOR(i, 0, m)
		{
			cin >> a >> b >> c;
			a--, b--;
			M[a][b] = M[b][a] = c;
		}
		int Q;
		cin >> Q;
		vector<pair<ii, ii>> qmin;
		vector<pair<ii, ii>> qmax;
		FOR(i, 0, Q)
		{
			int k, t;
			cin >> a >> b >> k >> t;
			a--, b--;
			if(t == 0)
			{
				qmin.emplace_back(mp(mp(k, i), mp(a, b)));
			}
			else
			{
				qmax.emplace_back(mp(mp(k, i), mp(a, b)));
			}
		}
		sort(all(qmin));
		sort(all(qmax));
		compute(qmin, Tmin);
		compute(qmax, Tmax);
		FOR(i, 0, Q)
			printf("%d\n", (ans[i] == INF ? -1 : ans[i]));
	}
	return 0;
}