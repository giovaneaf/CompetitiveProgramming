#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL

struct st
{
	int d, m;
	st (int d = 0, int m = 0) : d(d), m(m) {}
	bool operator< (const st s)
	{
		if(m == s.m) return d < s.d;
		return m < s.m;
	}
};

int n;
st cur(27, 10);
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool before(st& s)
{
	if(s.m > 10) return true;
	if(s.m == 10 && s.d > 27) return true;
	return false;
}

st lessOne(st& s)
{
	st ans = s;
	ans.d--;
	if(ans.d == 0)
	{
		ans.m--;
		if(ans.m == 0)
			ans.m = 12;
		ans.d = day[ans.m];
	}
	return ans;
}

int dist(st& a, st& b)
{
	int d = a.d;
	int m = a.m;
	int ans = 0;
	while(m != b.m || d > b.d)
	{
		ans += day[m] - d;
		d = 0;
		m++;
		if(m > 12)
			m = 1;
	}
	ans += b.d-d;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n)
	{
		vector<st> v(n);
		string s;
		FOR(i, 0, n)
		{
			cin >> s >> s;
			v[i].m = stoi(s.substr(0, 2));
			v[i].d = stoi(s.substr(3, 2));
		}
		if(n == 1 || (v[0].d == v[n-1].d && v[0].m == v[n-1].m))
		{
			st aa = lessOne(v[0]);
			printf("%02d-%02d\n", aa.m, aa.d);
			continue;
		}
		sort(v.begin(), v.end());
		int tmp, tmpdist, len, nxt, dis;
		st tmpans;
		len = 0;
		st ans;
		FOR(i, 0, n)
		{
			nxt = (i == n-1) ? 0 : i+1;
			tmp = dist(v[i], v[nxt]);
			tmpans = lessOne(v[nxt]);
			if(tmpans.d == cur.d && tmpans.m == cur.m) tmpdist = 400;
			else tmpdist = dist(cur, tmpans);
			if(tmp > 1 && len < tmp || (len == tmp && dis > tmpdist))
			{
				len = tmp;
				ans = tmpans;
				dis = tmpdist;
			}
		}
		printf("%02d-%02d\n", ans.m, ans.d);
	}
	return 0;
}