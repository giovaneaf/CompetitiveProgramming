#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAXN 1010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n, m, k;
string M[MAXN];
ii v[MAXN];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		cin >> n >> m >> k;
		priority_queue<int> pq;
		int best = INF;
		int ans = 0;
		FOR(i, 0, n)
		{
			cin >> M[i];
			v[i] = mp(0, 0);
			FOR(j, 0, m)
			{
				if(M[i][j] == '*') v[i].fst++;
				else v[i].snd++;
			}
			if(v[i].snd - v[i].fst > 0) pq.push(v[i].snd - v[i].fst);
			best = min(best, abs(v[i].fst - v[i].snd));
			ans += v[i].fst;
		}
		while(k > 0 && pq.size())
		{
			ans += pq.top();
			pq.pop();
			k--;
		}
		if(k&1) ans -= best;
		printf("%d\n", ans);
	}
	return 0;
}
