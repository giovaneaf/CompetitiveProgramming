#include <bits/stdc++.h>

#define MAXN 100010
#define INF 1e9
#define EPS 1e-9

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll l, r;
	cin >> l >> r;
	cout << "YES\n";
	for(ll i = l ; i <= r; i += 2)
	{
		cout << i << ' ' << i+1 << '\n';
	}
	return 0;
}









