#include <bits/stdc++.h>

#define INF 1000000000
#define MAXN 1010
#define EPS 1e-9

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int minimum = v[1]-v[0];
		for(int i = 2; i < n; ++i)
			minimum = min(minimum, v[i]-v[i-1]);
		cout << minimum << "\n";
	}
	return 0;
}