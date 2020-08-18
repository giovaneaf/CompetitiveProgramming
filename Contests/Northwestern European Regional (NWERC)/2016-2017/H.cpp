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
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n;
string a, b;

ll getBin(string& s)
{
	string ans;
	FOR(i, 0, n) s[i] -= '0';
	ans += s[0];
	FOR(i, 1, n)
	{
		ans += ans[(int) ans.size()-1]^s[i];
	}
	FOR(i, 0, n) ans[i] += '0';
	return stoll(ans, 0, 2);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		cin >> a >> b;
		printf("%lld\n", max(0LL, abs(getBin(a) - getBin(b)) - 1));
	}
	return 0;
}