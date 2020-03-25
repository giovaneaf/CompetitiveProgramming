#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q, k;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	ll v[3][3];
	while(cin >> v[0][0])
	{
		ll sum[3] = {0LL, 0LL, 0LL};
		sum[0] += v[0][0];
		for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < 3; ++j)
			{
				if(i == 0 && j == 0) continue;
				cin >> v[i][j];
				sum[j] += v[i][j];
			}
		}
		map<char, int> mm;
		mm['B'] = 0;
		mm['G'] = 1;
		mm['C'] = 2;
		string s("BCG");
		string ans("BCG");
		ll mn = 1000000000000000000LL;
		do
		{
			ll tmp = 0LL;
			FOR(i, 0, 3)
			{
				int pos = mm[s[i]];
				tmp += sum[pos] - v[i][pos];
			}
			if(mn > tmp)
			{
				mn = tmp;
				ans = s;
			}
		} while(next_permutation(s.begin(), s.end()));
		printf("%s %lld\n", ans.c_str(), mn);
	}
    return 0;
}