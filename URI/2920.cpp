#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	int k;
	while(cin >> s >> k)
	{
		int n = (int) s.size();
		if(k >= n)
		{
			printf("\n");
			continue;
		}
		int pos = 0;
		string ans;
		while(k > 0 && pos < n-k)
		{
			int best = pos;
			for(int i = pos+1; i <= pos+k && i < n; ++i)
			{
				if(s[i] < s[best]) best = i;
			}
			ans += s[best];
			k -= best-pos;
			pos = best+1;
		}
		if(k == 0)
		{
			while(pos < n) ans += s[pos++];
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}