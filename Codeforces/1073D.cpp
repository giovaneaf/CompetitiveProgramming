#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)

#define MAXN 510
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<ii> vii;

int n;
ll T;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> T)
	{
		vector<ll> a(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		ll ans = 0LL;
		while(true)
		{
			ll sum = 0LL;
			int candies = 0;
			for(int i = 0; i < n; ++i)
			{
				if(T >= a[i])
				{
					sum += a[i];
					candies++;
					T -= a[i];
				}
			}
			if(candies == 0) break;
			ans += candies;
			ans += ((ll) (T/sum))*candies;
			T %= sum;
		}
		cout << ans << '\n';
	}
}
