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

int n, k;
string s, tmp;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		cin >> s;
		set<string> seen;
		queue<string> q;
		q.push(s);
		int ans = k*(int) s.size();
		int cnt = 0;
		while(q.size())
		{
			s = q.front();
			q.pop();
			if(seen.count(s) > 0) continue;
			seen.insert(s);
			cnt++;
			ans -= s.size();
			FOR(i, 0, (int) s.size())
			{
				tmp = s;
				tmp.erase(tmp.begin()+i);
				q.push(tmp);
			}
			if(cnt == k) break;
		}
		if(cnt == k) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}
