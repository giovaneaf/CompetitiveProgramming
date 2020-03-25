#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9

const int INF = 1e9;
const ll llINF = 1e18;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n && n > 0)
	{
		map<long long, int> m;
		long long num[n];
		bool alone[n];
		int pos = 0;
		for(int i = 0; i < n; ++i)
		{
			long long nv;
			cin >> nv;
			if(m.find(nv) == m.end())
			{
				num[pos] = nv;
				alone[pos] = true;
				m[nv] = pos++;
			}
			else
			{
				alone[m[nv]] = !alone[m[nv]];	
			}
		}
		vector<long long> ans; 
		for(int i = 0; i < pos; ++i)
		{
			if(alone[i])
			{
				ans.push_back(num[i]);
			}
		}
		sort(ans.begin(), ans.end());
		printf("%lld", ans[0]);
		for(int i = 1; i < ans.size(); ++i)
		{
			printf(" %lld", ans[i]);
		}
		putchar('\n');
	}
}