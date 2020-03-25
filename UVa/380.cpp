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
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q, k;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	printf("CALL FORWARDING OUTPUT\n");
	FOR(t, 0, T)
	{
		printf("SYSTEM %d\n", t+1);
		int cnt = 0;
		int a, b, c, d;
		priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq[10010];
		while(true)
		{
			cin >> a;
			if(a == 0) break;
			cin >> b >> c >> d;
			pq[a].push(mp(b, mp(c, d)));
		}
		while(true)
		{
			cin >> a;
			if(a == 9000) break;
			cin >> b;
			while(pq[b].size() && pq[b].top().fst + pq[b].top().snd.fst < a) pq[b].pop();
			if(pq[b].empty() || pq[b].top().fst > a)
			{
				printf("AT %04d CALL TO %04d RINGS %04d\n", a, b, b);
			}
			else
			{
				int call = b;
				assert(pq[b].size());
				b = pq[b].top().snd.snd;
				bool can = false;
				while(b != call)
				{
					while(pq[b].size() && pq[b].top().fst + pq[b].top().snd.fst < a) pq[b].pop();
					if(pq[b].empty() || pq[b].top().fst > a)
					{
						printf("AT %04d CALL TO %04d RINGS %04d\n", a, call, b);
						can = true;
						break;
					}
					b = pq[b].top().snd.snd;
				}
				if(!can)
				{
					printf("AT %04d CALL TO %04d RINGS 9999\n", a, call, b);
				}
			}
		}
	}
	printf("END OF OUTPUT\n");
    return 0;
}