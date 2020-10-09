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
#define MAXN 200
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define DEBUG 0
 
int enter[MAXM];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		vi v(n);
		FOR(i, 0, n) cin >> v[i];
		fill(enter, enter+MAXM, -1);
		bool can = true;
		int l = 0;
		int cnt = 0;
		vector<int> ans;
		set<int> s;
		int x;
		FOR(i, 0, n)
		{
			x = v[i];
			if(x > 0)
			{
				if(s.find(x) != s.end())
				{
					can = false;
					break;
				}
				if(enter[x] > -1 && enter[x] >= l)
				{
					can = false;
					break;
				}
				s.insert(x);
				enter[x] = i;
			}
			else
			{
				if(s.find(-x) == s.end())
				{
					can = false;
					break;
				}
				s.erase(-x);
				if(s.empty())
				{
					ans.emplace_back(i-l+1);
					cnt++;
					l = i+1;
				}
			}
		}
		if(s.size())
		{
			can = false;
		}
		if(!can)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", cnt);
			FOR(i, 0, (int) ans.size())
			{
				if(i > 0) putchar(' ');
				printf("%d", ans[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}