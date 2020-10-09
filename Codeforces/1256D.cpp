#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;

#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 3001
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	ll n, k;
	string s;
	cin >> q;
	while(q--)
	{
		cin >> n >> k;
		cin >> s;
		//printf("%d %d %s\n", n, k, s.c_str());
		int last = 0;
		int pos = 0;
		while(pos < n && k > 0)
		{
			while(pos < n && s[pos] == '1') pos++;
			if(pos >= n) break;
			if(k - pos + last < 0)
			{
				swap(s[pos], s[pos-k]);
				break;
			}
			k -= pos - last;
			swap(s[pos], s[last]);
			last++;
			pos++;
		}
		printf("%s\n", s.c_str());
	}
	return 0;
}
