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
#define INF 1e9

int n;

inline bool ntob(int n)
{
	return (n & 1) == 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		stack<bool> s;
		for(int i = 0; i < n; ++i)
		{
			int v;
			cin >> v;
			if(s.empty()) s.push(ntob(v));
			else
			{
				if(s.top() ^ ntob(v)) s.push(ntob(v));
				else s.pop();	
			}
		}
		printf("%s\n", s.size() <= 1 ? "YES" : "NO");
	}
	return 0;
}