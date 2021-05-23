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
#define MAXN 5010
#define LOGMAXN 23
#define MAXM 1110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

int T;
int n, m;

struct State
{
	int pos;
	int last;
	bool falling;
	bool tight;
	State(int pos, int last, bool falling, bool tight) : pos(pos), last(last), falling(falling), tight(tight) {}
	bool operator< (const State& s) const
	{
		if(pos == s.pos)
			if(falling == s.falling)
				if(tight == s.tight)
					return last < s.last;
				else
					return tight < s.tight;
			else
				return falling < s.falling;
		else
			return pos < s.pos;
	}
};

string s;
int upper, upper1, upper2;

unsigned long long int solve(int pos, int last, bool falling, bool tight, map<State, unsigned long long int>& memo)
{
	if(pos == n)
		return tight ? 0ULL : 1ULL;
	State st = State(pos, last, falling, tight);
	if(memo.count(st) == 0)
	{
		unsigned long long int ans = 0LL;
		int upper, upper1, upper2;
		upper1 = (tight ? (s[pos]-'0'+1) : 10);
		upper2 = (falling ? last+1 : 10);
		upper = min(upper1, upper2);
		FOR(i, 0, upper)
		{
			ans += solve(pos+1, i, falling || (i < last), tight && (i == s[pos]-'0'), memo);
		}
		memo[st] = ans;
	}
	return memo[st];
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		FOR(t, 0, T)
		{
			cin >> s;
			map<State, unsigned long long int> memo;
			n = (int) s.size();
			bool hill = true;
			bool climbing = true;
			FOR(i, 1, (int) s.size())
			{
				if(s[i] < s[i-1])
				{
					climbing = false;
				}
				else if(s[i] > s[i-1] && !climbing)
				{
					hill = false;
					break;
				}
			}
			if(hill)
				printf("%llu\n", solve(0, -1, false, true, memo));
			else
				printf("-1\n");
		}
	}
	return 0;
}