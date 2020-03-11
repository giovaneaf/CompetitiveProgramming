#include <bits/stdc++.h>
#define MAXN 100010
 
using namespace std;
 
typedef long long ll;
 
ll v[MAXN];
 
int n;
 
ll Foo()
{
    priority_queue<ll> pq;
	for(int i = 0; i < n; ++i)
		pq.push(-v[i]);
	ll ans = 0LL;
	while(pq.size() > 1)
	{
		ll a = -pq.top(); pq.pop();
		ll b = -pq.top(); pq.pop();
		pq.push(-(a+b));
		ans += a+b;
	}
	return ans;
}
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> v[i];
        }
        ll ans = Foo();
        cout << ans << "\n";
    }
    return 0;
}