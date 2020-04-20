#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAXN 100010
#define LOGMAXN 20
#define MAXM 110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007

int T;
int n, a, b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> a >> b;
		string s;
		int pos = 0;
		while(pos < b)
		{
			s += pos + 'a';
			pos++;
		}
		while(pos < a)
		{
			s += 'a';
			pos++;
		}
		int x = 0;
		while(pos < n)
		{
			s += s[x++];
			pos++;
		}
		printf("%s\n", s.c_str());
	}
	return 0;
}

