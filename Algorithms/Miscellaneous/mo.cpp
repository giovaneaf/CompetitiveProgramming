#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> ip;
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
#define MAXN 300010
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
 
const ll mod = 1000000007LL;
int n, q;

struct Query
{
	int l, r, id;
	bool operator< (const Query q) const
	{
		int _sqrt = sqrt(n);
		int a, b;
		a = l/_sqrt;
		b = q.l/_sqrt;
		if(a == b)
			return r < q.r;
		return a < b;
	}
};

int a[MAXN];
int freq[MAXN];
Query query[MAXN];

// Mo algorithm to find most frequent number in an array with queries of type [l, r]

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	while(cin >> n >> q)
	{
		memset(freq, 0, sizeof(freq));
		FOR(i, 0, n)
		{
			cin >> a[i];
		}
		FOR(i, 0, q)
		{
			cin >> query[i].l >> query[i].r;
			query[i].l--; query[i].r--;
			query[i].id = i;
		}
		sort(query, query+q);
		int l, r;
		set<ii> s;
		l = query[0].l;
		r = query[0].l+1;
		freq[a[l]]++;
		s.insert(mp(freq[a[l]], a[l]));
		FOR(i, 0, q)
		{
			while(l < query[i].l)
			{
				s.erase(mp(freq[a[l]], a[l]));
				freq[a[l]]--;
				s.insert(mp(freq[a[l]], a[l]));
				l++;
			}
			while(l > query[i].l)
			{
				s.erase(mp(freq[a[l-1]], a[l-1]));
				freq[a[l-1]]++;
				s.insert(mp(freq[a[l-1]], a[l-1]));
				l--;
			}
			while(r <= query[i].r)
			{
				s.erase(mp(freq[a[r]], a[r]));
				freq[a[r]]++;
				s.insert(mp(freq[a[r]], a[r]));
				r++;
			}
			while(r > query[i].r+1)
			{
				s.erase(mp(freq[a[r-1]], a[r-1]));
				freq[a[r-1]]--;
				s.insert(mp(freq[a[r-1]], a[r-1]));
				r--;
			}
			auto it = s.end();
			it--;
			printf("in range [%d, %d] the most frequent number %d with %d ocurrences\n", l, r-1, it->snd, it->fst);
		}
	}
	return 0;
}