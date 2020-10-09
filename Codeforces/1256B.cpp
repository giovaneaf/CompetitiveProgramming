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
#define MAXN 3001
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	while(cin >> q)
	{
		while(q--)
		{
			int n;
			cin >> n;
			int v[MAXN];
			int idx[MAXN];
			priority_queue<ii, vector<ii>, greater<ii>> pq;
			FOR(i, 0, n)
			{
				cin >> v[i];
				pq.push(mp(v[i], i));
				idx[v[i]] = i;
			}
			int used = 0;
			while(pq.size())
			{
				ii p = pq.top();
				pq.pop();
				if(idx[p.fst] <= used)
				{
					used = (idx[p.fst] == used ? used+1 : used);
					continue;
				}
				for(int j = p.snd; j > used; --j)
				{
					idx[v[j]] = j-1;
					idx[v[j-1]] = j;
					swap(v[j], v[j-1]);
				}
				used = p.snd;
			}
			FOR(i, 0, n)
			{
				if(i > 0) putchar(' ');
				printf("%d", v[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}

