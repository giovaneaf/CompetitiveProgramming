/*
First of all duplicate the string because the string is a circle.
For each starting fruit (each position) you can compute how many pieces of cake are possible.
The formula is if you are at index i the number of possibles cakes is k - min(k, next[i]-i)
where next[i] is the position of the next 'E' in string (if i-th position has an 'E' then next[i] = i)
With this approach you'll not compute repeated pieces of cake.
The formula is k - min(k, next[i]-i) because the piece of cake is only valid when it has an 'E'.
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
	string s;
	while(cin >> s)
	{
		ll k;
		cin >> k;
		s += s;
		int n = (int) s.size();
		vector<ll> dist(n);
		int last = n;
		RFOR(i, n-1, 0)
		{
			if(s[i] == 'E') last = i;
			dist[i] = last-i;
		}
		ll ans = 0LL;
		FOR(i, 0, n/2)
		{
			ans += k - min(k, dist[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

