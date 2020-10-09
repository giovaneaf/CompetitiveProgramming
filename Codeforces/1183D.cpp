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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n, a;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		cin >> n;
		map<int, int> mm;
		FOR(i, 0, n)
		{
			cin >> a;
			mm[a]++;
		}
		priority_queue<ii> pq;
		for(auto it = mm.begin(); it != mm.end(); ++it)
		{
			pq.push(mp(it->snd, it->fst));
		}
		ii p;
		int mx = INF;
		int ans = 0;
		while(pq.size())
		{
			p = pq.top();
			pq.pop();
			if(mx <= p.fst)
			{
				mx--;
				ans += mx;
			}
			else
			{
				mx = p.fst;
				ans += mx;
			}
			if(mx == 1) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
