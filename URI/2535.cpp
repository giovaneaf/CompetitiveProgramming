#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define MAXN 10010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1e9;
const ll llINF = 1e18;
const int mod = 1000000;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	while(cin >> n)
	{
		getline(cin, s);
		int ans = 0;
		for(int i = 0; i < n; ++i)
		{
			getline(cin, s);
			if(s == "cachorro")
			{
				getline(cin, s);
				char ch = s[0];
				getline(cin, s);
				stringstream ss(s);
				int cnt = 1;
				bool b = false;
				ss >> s;
				if(s[0] == ch) b = true;
				while(ss >> s) 
				{
					if(s[0] == ch) b = true;
					cnt++;
				}
				if(cnt > 1 && b)
				{
					ans++;
				}
			}
			else
			{
				getline(cin, s);
				getline(cin, s);
			}
			getline(cin, s);
		}
		printf("%d\n", ans);
	}
	return 0;
}