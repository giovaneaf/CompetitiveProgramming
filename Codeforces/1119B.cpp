#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define MAXN 100010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9

int n, h;

bool can(int k, vi& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	FOR(i, 0, k+1)
	{
		pq.push(v[i]);
	}
	int curH = h;
	if(pq.size()&1)
	{
		int sz = pq.top();
		pq.pop();
		curH -= sz;
	}
	while(pq.size() && curH > 0)
	{
		int sz = pq.top();
		pq.pop();
		if(pq.size())
		{
			sz = max(sz, pq.top());
			pq.pop();
		}
		curH -= sz;
	}
	return pq.empty() && curH >= 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> h;
	vi v(n);
	FOR(i, 0, n)
	{
		cin >> v[i];
	}
	int l = 0;
	int r = n-1;
	while(r - l > 1)
	{
		int mid = (r+l)>>1;
		if(can(mid, v))
		{
			l = mid;
		}
		else
		{
			r = mid-1;
		}
	}
	printf("%d\n", (can(r, v) ? r : l)+1);
	return 0;
}