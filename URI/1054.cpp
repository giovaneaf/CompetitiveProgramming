#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXN 10000010
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
const ll mod = 1000000007LL;

struct rock
{
	bool big;
	ll len;
};
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	FOR(t, 0, T)
	{
		int n, d;
		cin >> n >> d;
		string s;
		vector<rock> v(n+2);
		v[0] = {true, 0};
		v[n+1] = {true, d};
		FOR(i, 1, n+1)
		{
			cin >> s;
			v[i].big = false;
			v[i].len = stoll(s.substr(2));
			if(s[0] == 'B')
				v[i].big = true;
		}
		ll mxleap = 0LL;
		FOR(i, 1, n+2)
		{
			if(v[i-1].big)
			{
				mxleap = max(mxleap, v[i].len - v[i-1].len);
			}
			else
			{
				mxleap = max(mxleap, v[i].len - v[i-2].len);
			}
		}
		printf("Case %d: %lld\n", t+1, mxleap);
	}
	return 0;
}