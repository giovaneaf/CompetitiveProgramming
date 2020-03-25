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
#define comp(a, b) ((a)+(b))
const int neutral = 0;
 
class FenwickTree
{
	public:
		vector<int> ft;
	FenwickTree(int n) { ft.assign(n+1, 0); }
	int rsq(int i) {
		int sum = neutral;
		for(; i; i-= (i&-i))
			sum = comp(sum, ft[i]);
		return sum;
	}
	int rsq(int i, int j)
	{
		return rsq(j) - rsq(i-1);
	}
	void update(int i, int v)
	{
		for(; i < (int) ft.size(); i += (i & -i))
			ft[i] = comp(v, ft[i]);
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		map<int, int> mm;
		int v[n];
		vi sorted(n);
		FOR(i, 0, n)
		{
			cin >> v[i];
			sorted[i] = v[i];
		}
		sort(sorted.begin(), sorted.end());
		FOR(i, 0, n)
		{
			mm[sorted[i]] = i+1;
		}
		FenwickTree ft(n);
		ll sum = 0LL;
		FOR(i, 0, n)
		{
			int num = mm[v[i]];
			sum += ft.rsq(num+1, n);
			ft.update(num, 1);
		}
		printf("%lld\n", sum);
	}
	return 0;
}  