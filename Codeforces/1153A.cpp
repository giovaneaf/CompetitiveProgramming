#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 4100
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n, t;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> t)
	{
		set<ii> s;
		FOR(i, 0, n)
		{
			int a, b;
			cin >> a >> b;
			if(a >= t)
			{
				s.insert(mp(a, i));
			}
			else
			{
				int gap = t-a;
				int sum = gap/b;
				int val = sum*b+a;
				if(val < t) val += b;
				//printf("%d\n", val);
				s.insert(mp(val, i));
			}
		}
		printf("%d\n", s.begin()->second+1);
	}
}