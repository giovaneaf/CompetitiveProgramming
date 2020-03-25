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
#define MAXN 500010
#define MAXM 44100
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int n;
set<vi> ans;

void solve(int depth, vi curSet, vi curSum)
{
	auto it = lower_bound(curSum.begin(), curSum.end(), 0);
	if(it == curSum.end() || *it > 0)
		return ;
	if(depth == n+1)
	{
		sort(curSet.begin(), curSet.end());
		ans.insert(curSet);
		return ;
	}
	int curSize = (int) curSum.size();
	int newVal = curSum[curSize-1]-curSum[curSize-2];
	int deletions = 0;
	vb use(curSize, true);
	int lp = 0;
	int rp = 1;
	while(rp < curSize)
	{
		while(lp < curSize && !use[lp]) lp++;
		if(lp >= rp)
			rp = lp+1;
		while(rp < curSize && curSum[lp]+newVal > curSum[rp])
		{
			rp++;
		}
		if(curSum[lp]+newVal == curSum[rp])
		{
			deletions++;
			use[rp] = false;
			rp++;
		}
		lp++;
	}
	//printf("%d %d %d\n", newVal, deletions, n-depth);
	if(deletions == (1 << (n-depth)))
	{
		curSet.emplace_back(newVal);
		vi tmpSum((1 << (n-depth)));
		int pos = 0;
		FOR(i, 0, curSize)
		{
			if(use[i])
				tmpSum[pos++] = curSum[i];
		}
		solve(depth+1, curSet, tmpSum);
		curSet.pop_back();
	}
	if(curSum[curSize-1] != curSum[curSize-2])
	{
		newVal = curSum[curSize-2]-curSum[curSize-1];
		int deletions = 0;
		use.assign(curSize, true);
		int lp = 0;
		int rp = 1;
		while(rp < curSize)
		{
			while(lp < curSize && !use[lp]) lp++;
			if(lp >= rp)
				rp = lp+1;
			while(rp < curSize && curSum[lp]-newVal > curSum[rp])
			{
				rp++;
			}
			if(curSum[lp]-newVal == curSum[rp])
			{
				deletions++;
				use[rp] = false;
				rp++;
			}
			lp++;
		}
		if(deletions == (1 << (n-depth)))
		{
			curSet.emplace_back(newVal);
			vi tmpSum((1 << (n-depth)));
			int pos = 0;
			FOR(i, 0, curSize)
			{
				if(!use[i])
					tmpSum[pos++] = curSum[i];
			}
			solve(depth+1, curSet, tmpSum);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vi vs((1 << n));
		FOR(i, 0, (1 << n))
		{
			int x;
			cin >> x;
			vs[i] = x;
		}
		sort(vs.begin(), vs.end());
		solve(1, vi(), vs);
		bool first;
		for(vi vv : ans)
		{
			string s;
			s += to_string(vv[0]);
			FOR(i, 1, vv.size())
			{
				s += ' ' + to_string(vv[i]);
			}
			printf("%s\n", s.c_str());
		}
		for(vi a : ans)
			a.clear();
	}
	return 0;
}
