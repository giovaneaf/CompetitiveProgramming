#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 100010
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
ll mod = 1000000007LL;
int n, k, mask;
string str;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		queue<int> q;
		vi L(1 << k, -1);
		FOR(i, 0, n)
		{
			cin >> str;
			mask = 0;
			FOR(j, 0, k)
			{
				mask |= ((str[j]-'0') << j);
			}
			q.push(mask);
			L[mask] = 0;
		}
		int cur;
		while(q.size()) 	// multi source BFS
		{
			cur = q.front();
			q.pop();
			FOR(i, 0, k)
			{
				mask = cur ^ (1 << i);
				if(L[mask] == -1)	// if not seen
				{
					L[mask] = 1 + L[cur];
					q.push(mask);
				}
			}
		}
		FOR(i, 0, k)
		{
			printf("%d", (cur & (1 << i)) ? 1 : 0);
		}
		puts("");
	}
	return 0;
}
