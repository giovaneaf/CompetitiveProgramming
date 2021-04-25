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
#define MAXN 110
#define LOGMAXN 23
#define MAXM 1000010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

const ll mod = 1000000007LL;

int n;
string str;

struct Match
{
	int gm[2] = {0, 0};
	int pt[2] = {0, 0};
	int sv = 0;
	
	void process(char& c)
	{
		if(c == 'Q')
		{
			print();
			return ;
		}
		if(c == 'R') sv ^= 1;
		score();
	}
	
	void score()
	{
		if(gm[0] == 2 || gm[1] == 2) return ;
		pt[sv]++;
		if(pt[sv] == 10 || (pt[sv] >= 5 && pt[sv] - pt[sv^1] >= 2))
		{
			gm[sv]++;
			pt[sv] = pt[sv^1] = 0;
		}
	}
	
	void print()
	{
		if(gm[0] == 2)
		{
			printf("%d (winner) - %d\n", gm[0], gm[1]);
			return ;
		}
		if(gm[1] == 2)
		{
			printf("%d - %d (winner)\n", gm[0], gm[1]);
			return ;
		}
		printf("%d (%d%s) - %d (%d%s)\n", gm[0], pt[0], sv == 0 ? "*" : "", gm[1], pt[1], sv == 1 ? "*" : "");
	}
	
};

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> str)
	{
		Match match;
		for(char& c : str)
		{
			match.process(c);
		}
	}
	return 0;
}