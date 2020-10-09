#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 110
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vector<int> v(n);
		for(int i = 0; i < n; ++i)
			cin >> v[i];
		sort(v.begin(), v.end());
		vector<bool> seen(n, false);
		int ans = 0;
		for(int i = 0; i < n; ++i)
		{
			if(seen[i]) continue;
			int sz = 1;
			for(int j = i+1; j < n; ++j)
			{
				if(seen[j]) continue;
				if(v[j] >= sz)
				{
					seen[j] = true;
					sz++;
				}
			}
			ans++;
		}
		cout << ans << '\n';
	}
    return 0;
}

