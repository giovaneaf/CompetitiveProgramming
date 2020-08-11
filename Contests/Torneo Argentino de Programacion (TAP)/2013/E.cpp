#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAXN 1000001
#define LOGMAXN 21
#define MAXM 250010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int T, n;
string str;
int pw[20];

bool can(int len)
{
	set<int> s;	// contains all masks of the string with length len
	int ptr, mask;
	ptr = mask = 0;
	while(ptr+1 <= len)
	{
		mask = (mask << 1) | str[ptr];
		ptr++;
	}
	s.insert(mask);
	while(ptr < n)
	{
		mask = ((mask << 1) & (~(1 << len))) | str[ptr];
		s.insert(mask);
		ptr++;
	}
	return (int) s.size() < pw[len];	// the size need to be less than 2^len
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	pw[0] = 1;
	FOR(i, 1, 20) pw[i] = 2*pw[i-1];
	while(T--)
	{
		cin >> str;
		n = (int) str.size();
		FOR(i, 0, n) str[i] -= '0';
		int l, h, mid;
		// 17 is upper bound because the length of the 
		// string should be 2^17 to have all possible 
		// binary strings of length 17
		l = 1; h = 17;
		while(h - l > 1)
		{
			mid = (h+l) >> 1;
			if(can(mid)) h = mid;
			else l = mid+1;
		}
		printf("%d\n", can(l) ? l : h);
	}
	return 0;
}
