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
#define MAXN 40000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0
 
const ll mod = 11092019LL;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s)
	{
		vector<ll> freq(26, 0LL);
		for(char& c : s)
		{
			freq[c-'a']++;
		}
		ll ans = 1LL;
		FOR(i, 0, 26)
		{
			ans = (ans*(freq[i]+1))%mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
close