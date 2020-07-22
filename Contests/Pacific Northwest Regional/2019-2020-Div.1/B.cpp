#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
int n, k;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		vi v(n);
		FOR(i, 0, n)
		{
			cin >> v[i];
		}
		vb used(k+1, false);
		stack<int> s;
		RFOR(i, n-1, 0)
		{
			if(!used[v[i]])
			{
				used[v[i]] = true;
				s.push(i);
			}
		}
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		fill(used.begin(), used.end(), false);
		vi ans(k);
		int l = 0;
		int pos = 0;
		int li = -1; // last index
		while(s.size())
		{
			while(s.size() && used[v[s.top()]]) 
			{
				s.pop();
			}
			if(s.size())
			{
				while(l <= s.top())
				{
					pq.push({v[l], l});
					l++;
				}
				s.pop();
			}
			while(pq.size())
			{
				ii p = pq.top();
				pq.pop();
				if(li > p.snd || used[p.fst])
				{
					if(p.snd == l-1) break;
					else continue;
				}
				li = p.snd;
				ans[pos++] = p.fst;
				used[p.fst] = true;
				if(p.snd == l-1) break;
			}
		}
		FOR(i, 0, k)
		{
			if(i > 0) putchar(' ');
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}