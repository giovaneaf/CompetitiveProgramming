#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 30010
#define FOR(a, b, c) for(int a = b; a < c; a++)
#define mp(a, b) make_pair(a, b)
 
 
int n, sqrtn;
 
bool cmp(const pair<ii, int>& st, const pair<ii, int>& nd)
{
	int block1 = st.first.first/sqrtn;
	int block2 = nd.first.first/sqrtn;
	if(block1 < block2 || (block1 == block2 && st.first.second < nd.first.second))
		return true;
	return false;
}
 
int main()
{
	scanf("%d", &n);
	sqrtn = sqrt(n);
	int v[n];
	FOR(i, 0, n) scanf("%d", &v[i]);;
	vector<int> f(1000010, 0);
	int q;
	scanf("%d", &q);
	vector<pair<ii, int>> query(q);
	FOR(i, 0, q)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		query[i] = mp(mp(a, b), i);
	}
	sort(query.begin(), query.end(), cmp);
	int ans[q];
	int cl, cr;
	int cnt = 0;
	cl = cr = query[0].first.first;
	f[v[cl]]++;
	cnt++;
	FOR(i, 0, q)
	{
		int l, r;
		l = query[i].first.first; r = query[i].first.second;
		while(cl < l)
		{
			f[v[cl]]--;
			if(f[v[cl]] == 0) cnt--;
			cl++;
		}
		while(cl > l)
		{
			cl--;
			f[v[cl]]++;
			if(f[v[cl]] == 1) cnt++;
		}
		while(cr < r)
		{
			cr++;
			f[v[cr]]++;
			if(f[v[cr]] == 1) cnt++;
		}
		while(cr > r)
		{
			f[v[cr]]--;
			if(f[v[cr]] == 0) cnt--;
			cr--;
		}
		ans[query[i].second] = cnt;
	}
	FOR(i, 0, q)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
} 