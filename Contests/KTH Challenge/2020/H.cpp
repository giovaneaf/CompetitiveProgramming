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
#define MAXN 5010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

int n;
int votes[MAXN];
int points[MAXN];
int zero[MAXN];
int one[MAXN];
int memo[MAXN][3*MAXN];
string s;

inline int getVote(char c)
{
	if(c == '2') return -1;
	return c - '0';
}

inline int getPts(int x)
{
	if(x == 0) return 0;
	if(x > 0) return 1;
	return -1;
}

void print(int* arr)
{
	FOR(i, 0, n)
	{
		printf("%2d ", arr[i] == INF ? -1 : arr[i]);
	}
	putchar('\n');
}

inline int getPos(int points)
{
	return 5000+points;
}

inline int getPoints(int pos)
{
	return pos-5000;
}

int solve(int cur, int pos)
{
	if(cur == n) return (getPoints(pos) > 0 ? 0 : INF);
	if(memo[cur][pos] == -1)
	{
		int ans;
		if(s[cur] == '0')
		{
			int npos = pos + getPts(votes[cur]);
			ans = solve(cur+1, npos);
			int tmp;
			if(votes[cur] <= 0)
			{
				if(zero[cur] < INF)
				{
					tmp = solve(cur+1, pos);
					if(tmp != INF)
					{
						ans = min(ans, tmp + zero[cur]);
					}
				}
				if(one[cur] < INF)
				{
					tmp = solve(cur+1, pos+1);
					if(tmp != INF)
					{
						ans = min(ans, tmp + one[cur]);
					}
				}
			}
		}
		else
		{
			ans = solve(cur+1, pos);
		}
		memo[cur][pos] = ans;
	}
	return memo[cur][pos];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		cin >> s;
		votes[0] = getVote(s[0]);
		points[0] = 0;
		FOR(i, 1, n)
		{
			votes[i] = votes[i-1] + getVote(s[i]);
			points[i] = points[i-1];
			if(votes[i] == votes[i-1] && votes[i] != 0) // is teller
			{
				points[i] += (votes[i] < 0 ? -1 : 1);
			}
		}
		memset(zero, INF, sizeof(zero));
		memset(one, INF, sizeof(one));
		FOR(i, 0, n)
		{
			if(s[i] == '0')
			{
				if(votes[i] > 0) continue;
				int a = i;
				int cnt = 0;
				int prevcnt = 0;
				while(a >= 0)
				{
					if(zero[i] == INF && votes[a] == 0)
					{
						zero[i] = prevcnt;
					}
					else if(one[i] == INF && votes[a] > 0)
					{
						one[i] = prevcnt;
					}
					a--;
					prevcnt = cnt;
					if(a >= 0) cnt += (s[a] == '0' ? 0 : 1);
				}
				if(zero[i] == INF)
				{
					zero[i] = prevcnt;
				}
				a = i;
				cnt = 0;
				while(a < n)
				{
					if(zero[i] > cnt && votes[a] == 0)
					{
						zero[i] = cnt;
					}
					else if(one[i] > cnt && votes[a] > 0)
					{
						one[i] = cnt;
					}
					a++;
					if(a < n) cnt += (s[a] == '0' ? 0 : 1);
				}
			}
		}
		memset(memo, -1, sizeof(memo));
		solve(0, getPos(0));
		if(memo[0][getPos(0)] == INF) printf("impossible");
		else printf("%d", memo[0][getPos(0)]);
		puts("");
	}
	return 0;
}