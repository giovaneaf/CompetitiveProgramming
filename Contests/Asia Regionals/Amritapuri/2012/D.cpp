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

int T, n;
string str;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	FOR(t, 0, T)
	{
		cin >> str;
		n = (int) str.size();
		bool magical = true;
		set<string> s;
		FOR(i, 0, n) FOR(j, i, n) s.insert(str.substr(i, j-i+1));
		for(auto it = s.begin(); it != s.end(); ++it)
		{
			str = *it;
			reverse(all(str));
			if(s.find(str) == s.end())
			{
				magical = false;
				break;
			}
		}
		printf("%s\n", magical ? "YES" : "NO");
	}
	return 0;
}
