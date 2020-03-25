#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
const int mod = 1000000;
int n, b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> b)
	{
		int v[n];
		int acc[n+1];
		acc[0] = 0;
		FOR(i, 0, n) cin >> v[i], acc[i+1] = acc[i] + v[i];
		multiset<int> ms;
		FOR(i, 0, b)
		{
			ms.insert(v[i]);
		}
		ll sum = 0;
		sum += acc[b];
		sum -= *ms.begin();
		auto it = ms.end();
		it--;
		sum-= *it;
		FOR(i, 1, n-b+1)
		{
			ms.erase(ms.find(v[i-1]));
			ms.insert(v[i+b-1]);
			sum += acc[i+b] - acc[i];
			sum -= *ms.begin();
			auto it = ms.end();
			it--;
			sum-= *it;
		}
		printf("%lld\n", sum);
	}
	return 0;
}