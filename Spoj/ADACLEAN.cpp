#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)
 
#define MAXN 100010
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
 
  
ll power(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}
 
ll modInverse(ll a, ll m) 
{ 
    return power(a, m-2, m); 
}
 
const int p1 = 31, p2 = 53;
const ll mod1 = MOD, mod2 = MOD+2; 
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		set<pair<ll, ll>> st;
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<long long> power1(n);
		vector<long long> h1(n+1);
		power1[0] = 1LL;
		h1[0] = 0LL;
		for(int i = 1; i < n; ++i)
		{
			power1[i] = (power1[i-1]*p1)%mod1;
			h1[i] = (h1[i-1] + (s[i-1] - 'a' + 1)*power1[i-1])%mod1;
		}
		h1[n] = (h1[n-1] + (s[n-1] - 'a' + 1)*power1[n-1])%mod1;
		vector<long long> power2(n);
		vector<long long> h2(n+1);
		power2[0] = 1LL;
		h2[0] = 0LL;
		for(int i = 1; i < n; ++i)
		{
			power2[i] = (power2[i-1]*p2)%mod2;
			h2[i] = (h2[i-1] + (s[i-1] - 'a' + 1)*power2[i-1])%mod2;
		}
		h2[n] = (h2[n-1] + (s[n-1] - 'a' + 1)*power2[n-1])%mod2;
		for(int i = k; i <= n; ++i)
		{
			ll hv1, hv2;
			if(i == k)
			{
				hv1 = h1[i];
				hv2 = h2[i];
			}
			else
			{
				hv1 = (((h1[i]-h1[i-k] + mod1)%mod1)*modInverse(power1[i-k], mod1))%mod1;
				hv2 = (((h2[i]-h2[i-k] + mod2)%mod2)*modInverse(power2[i-k], mod2))%mod2;;
			}
			st.insert({hv1, hv2});
		}
		cout << st.size() << '\n';
	}
	return 0;
} 