#include <bits/stdc++.h>
 
#define MAXN 1000001
#define MOD 10000007
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
 
ll dp[5010];
 
ll B(string& s, int i)
{
	if(i == (int) s.size()) return 1;
	if(dp[i] == -1LL)
	{
		ll ans = B(s, i+1);
		if(i < s.size()-1 && stoi(s.substr(i, 2)) <= 26)
			ans += B(s, i+2);
		dp[i] = ans;
	}
	return dp[i];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(cin >> s)
	{
		if(s.size() == 1 && s[0] == '0') break;
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i] == '0')
				dp[i] = 0LL;
			else
				dp[i] = -1LL;
		}
		cout << B(s, 0) << "\n";
	}
    return 0;
}