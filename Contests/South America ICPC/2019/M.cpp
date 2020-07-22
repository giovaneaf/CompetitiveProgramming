/*
You can just scan the array and check the higher streak where the 
difference is less than or equal to x.
*/

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
	int n, x;
	while(cin >> n >> x)
	{
		int a;
		int ans = 1;
		int cnt = 1;
		int last;
		cin >> last;
		n--;
		while(n--)
		{
			cin >> a;
			if(abs(a - last) <= x) cnt++;
			else cnt = 1;
			ans = max(ans, cnt);
			last = a;
		}
		printf("%d\n", ans);
	}
	return 0;
}

