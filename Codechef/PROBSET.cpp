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
		int n, m;
		cin >> n >> m;
		bool a, b;
		a = b = false;
		for(int i = 0; i < n; ++i)
		{
			string s, t;
			cin >> s >> t;
			if(s[0] == 'c')
			{
				for(int j = 0; j < t.size(); ++j)
				{
					if(t[j] == '0')
					{
						a = true;
						break;
					}
				}
			}
			else
			{
				int j = 0;
				for(; j < t.size(); ++j)
					if(t[j] == '0') break;
				if(j == t.size())
					b = true;
			}
		}
		string ans;
		if(a) ans = "INVALID";
		else if(b) ans = "WEAK";
		else ans = "FINE";
		cout << ans << "\n";			
	}
	return 0;
}