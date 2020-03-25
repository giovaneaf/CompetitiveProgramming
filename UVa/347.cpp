#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 100010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q, k;

string str;

bool next(int mask, int pos, bool tight)
{
	if(pos == (int) str.size()) return true;
	FOR(i, 0, 10)
	{
		if((i < str[pos] - '0' && tight) || ((mask & (1 << i)) > 0)) continue;
		bool newtight = tight && (str[pos] - '0' == i);
		str[pos] = i + '0';
		if(next(mask | (1 << i), pos+1, newtight))
		{
			return true;
		}
	}
	return false;
}

void getNext()
{
	ll v = stoll(str);
	v++;
	str = to_string(v);
	if(!next(0, 0, true))
	{
		str.push_back('0');
		int n = str.size();
		str[0] = '1';
		FOR(i, 1, n)
		{
			str[i] = '0';
		}
		next(0, 0, true);
	}
}

void first()
{
	int n = str.size();
	vb seen(10, false);
	FOR(i, 0, n)
	{
		if(seen[str[i]-'0'])
		{
			getNext();
			break;
		}
		seen[str[i]-'0'] = true;
	}
}

bool runAround()
{
	int n = str.size();
	int pos = 0;
	vb seen(n, false);
	FOR(i, 0, n)
	{
		if(seen[pos]) return false;
		seen[pos] = true;
		pos = (pos + (str[pos] - '0'))%n;
	}
	return pos == 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while(cin >> str)
	{
		if(str[0] == '0') break;
		first();
		while(!runAround())
		{
			getNext();
		}
		printf("Case %d: %s\n", t++, str.c_str());
	}
    return 0;
}
