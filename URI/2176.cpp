#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 300010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int ans = 0;
	FOR(i, 0, (int) s.size())
	{
		if(s[i] == '1') ans++;
	}
	cout << s << ((ans&1) ? '1' : '0') << '\n';
	return 0;
}
