#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = INT_MAX;
	string ans = s;
	string perm("BGR");
	do
	{
		string tmp = s;
		int cn = 0;
		for(int i = 0; i < n; ++i)
		{
			if(perm[i%3] != tmp[i]) cn++;
			tmp[i] = perm[i%3];
		}
		if(cn < cnt)
		{
			cnt = cn;
			ans = tmp;
		}
	} while(next_permutation(perm.begin(), perm.end()));
	cout << cnt << '\n' << ans << '\n';
	return 0;
}