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
#define MAXN 300010
#define LOGMAXN 23
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n, k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k)
	{
		map<string, int> mm;
		set<int> s[n];
		int store; string item;
		int id = 0;
		FOR(i, 0, k)
		{
			cin >> store >> item;
			if(mm.find(item) == mm.end())
			{
				mm[item] = id++;
			}
			s[store].insert(mm[item]);
		}
		cin >> k;
		vi v(k);
		FOR(i, 0, k)
		{
			cin >> item;
			if(mm.find(item) == mm.end())
			{
				mm[item] = id++;
			}
			v[i] = mm[item];
		}
		int pos;
		vi ans(k);
		pos = 0;
		FOR(i, 0, n)
		{
			if(pos == k) break;
			while(pos < k && s[i].find(v[pos]) != s[i].end())
			{
				ans[pos++] = i;
			}
		}
		if(pos < k)
		{
			printf("impossible\n");
			continue;
		}
		bool ambiguous = false;
		pos = k-1;
		RFOR(i, n-1, 0)
		{
			if(pos == -1) break;
			while(pos >= 0 && s[i].find(v[pos]) != s[i].end())
			{
				if(ans[pos] != i)
				{
					ambiguous = true;
					break;
				}
				pos--;
			}
			if(ambiguous) break;
		}
		printf("%s\n", ambiguous ? "ambiguous" : "unique");
	}
	return 0;
}