#include <bits/stdc++.h>

#define INF 1000000000
#define MAXN 1010
#define EPS 1e-9

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

int dp[12][2][12];

int solve(int pos, string& s, bool tight, int nt)
{
	if(pos == s.size()) return (nt >= 3 ? 1 : 0);
	if(dp[pos][tight][nt] != -1) return dp[pos][tight][nt];
	int ans = 0;
	for(int i = (tight ? s[pos] - '0' : 0); i < 10; ++i)
	{
		if(solve(pos+1, s, tight && (i == (s[pos] - '0')), nt + (i == 3)))
		{
			s[pos] = i + '0';
			ans = true;
			break;
		}
	}
	return dp[pos][tight][nt] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		s[s.size()-1]++;
		string ans = s;
		memset(dp, -1, sizeof(dp));
		if(!solve(0, ans, true, 0))
		{
			int size = max(3, (int) s.size()+1);
			ans.resize(size);
			ans[0] = '1';
			for(int i = 1; i < ans.size()-3; ++i)
				ans[i] = '0';
			for(int i = ans.size()-3; i < ans.size(); ++i)
				ans[i] = '3';
		}
		cout << ans << "\n";
	}
	return 0;
}