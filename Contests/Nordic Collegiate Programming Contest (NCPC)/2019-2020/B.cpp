#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;
int n;
ll ans;

pair<ll, ll> v[3];
pair<ll, ll> t[3];

void solve(int pos)
{
	if(pos == 3)
	{
		FOR(i, 0, 3) t[i] = v[i];
		sort(t, t+3);
		ll area;
		do
		{
			area = max(t[0].fst + t[1].fst, t[2].fst)*(max(t[0].snd, t[1].snd) + t[2].snd);
			area = min(max(t[0].snd, t[1].snd+t[2].snd)*(max(t[1].fst, t[2].fst) + t[0].fst), area);
			area = min(max(t[0].snd, max(t[1].snd, t[2].snd))*(t[0].fst + t[1].fst + t[2].fst), area);
			ans = min(area, ans);
		} while(next_permutation(t, t+3));
		return ;
	}
	solve(pos+1);
	swap(v[pos].fst, v[pos].snd);
	solve(pos+1);
	swap(v[pos].fst, v[pos].snd);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		while(n--)
		{
			FOR(i, 0, 3)
			{
				cin >> v[i].fst >> v[i].snd;
			}
			ans = INFLL;
			solve(0);
			cout << ans << '\n';
		}
	}
	return 0;
}