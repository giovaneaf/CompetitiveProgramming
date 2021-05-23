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
#define MAXM 1110
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define MAXWORDS 1010
 
ll mod = 1000000007LL;

int T;
int n;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		string expr;
		while(T--)
		{
			cin >> expr;
			string a[3];
			if(expr[0] == '-')
			{
				a[0] = '-';
				expr = expr.substr(1);
			}
			int op;
			size_t pos = expr.find('=');
			a[2] = expr.substr(pos+1);
			expr = expr.substr(0, pos);
			pos = expr.find('*');
			if(pos != string::npos)
			{
				op = 0;
			}
			else
			{
				pos = expr.find('+');
				if(pos != string::npos)
				{
					op = 1;
				}
				else
				{
					pos = expr.find('-');
					op = 2;
				}
			}
			a[0] += expr.substr(0, pos);
			a[1] = expr.substr(pos+1);
			vector<bool> valid(10, true);
			int start = 0;
			if((a[0][0] == '?' && (int) a[0].size() > 1) || (a[0][0] == '-' && a[0][1] == '?') || 
			   (a[1][0] == '?' && (int) a[1].size() > 1) || (a[1][0] == '-' && a[1][1] == '?') ||
			   (a[2][0] == '?' && (int) a[2].size() > 1) || (a[2][0] == '-' && a[2][1] == '?'))
			{
				valid[0] = false;
			}
			FOR(j, 0, 3)
			{
				FOR(k, 0, a[j].size())
				{
					if('0' <= a[j][k] && a[j][k] <= '9')
					{
						valid[a[j][k]-'0'] = false;
					}
				}
			}
			string aa[3];
			aa[0] = a[0]; aa[1] = a[1]; aa[2] = a[2];
			int ans = -1;
			ll expected;
			FOR(i, 0, 10)
			{
				if(!valid[i]) continue;
				FOR(j, 0, 3)
				{
					FOR(k, 0, a[j].size())
					if(a[j][k] == '?')
						aa[j][k] = (i+'0');
				}
				if(op == 0)
				{
					expected = stoll(aa[0])*stoll(aa[1]);
				}
				else if(op == 1)
				{
					expected = stoll(aa[0])+stoll(aa[1]);
				}
				else
				{
					expected = stoll(aa[0])-stoll(aa[1]);
				}
				if(expected == stoll(aa[2]))
				{
					ans = i;
					break;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}