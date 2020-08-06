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
#define MAXN 10010
#define LOGMAXN 20
#define MAXM 100010
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9

ll mod = 1000000007LL;

int n, ans;
string str[MAXN];
char rev[15];
int v[15];
vb marked;
char myMap[15];

ll getNum(string s, map<char, int>& mm)
{
	ll ans = 0LL;
	ll pow = 1LL;
	RFOR(i, (int) s.size()-1, 0)
	{
		ans += pow*(v[mm[s[i]]]);
		pow *= 10LL;
	}
	return ans;
}

string getStr(ll num)
{
	string ans;
	while(num > 0LL)
	{
		ans += myMap[num%10LL];
		num /= 10LL;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void solve(int pos, vb& used, map<char, int>& mm)
{
	if(pos == (int) mm.size())
	{
		ll num = getNum(str[0], mm);
		FOR(i, 1, n-1)
			num += getNum(str[i], mm);
		if(getStr(num) == str[n-1])
		{
			ans++;
		}
		return ;
	}
	FOR(i, 0, 10)
	{
		if(used[i] || (marked[pos] && i == 0)) continue;
		used[i] = true; v[pos] = i; myMap[i] = rev[pos];
		solve(pos+1, used, mm);
		used[i] = false; myMap[i] = '0';
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		map<char, int> mm;
		marked.assign(10, false);
		int cnt = 0;
		FOR(i, 0, n)
		{
			cin >> str[i];
			for(char& c : str[i])
			{
				if(mm.find(c) == mm.end())
				{
					rev[cnt] = c;
					mm[c] = cnt++;
				}
			}
			marked[mm[str[i][0]]] = true;
		}
		ans = 0;
		vb used(10, false);
		solve(0, used, mm);
		printf("%d\n", ans);
	}
	return 0;
}
