#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
 
int n;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n && n)
	{
		ll ans = 0LL;
		ll hand = 0LL;
		for(int i = 0; i < n; ++i)
		{
			ll v;
			cin >> v;
			ans += llabs(hand);
			hand += v;
		}
		cout << ans << '\n';
	}
	return 0;
} 