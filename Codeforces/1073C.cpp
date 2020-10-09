#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)

#define MAXN 510
#define LOGMAXN 20
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<ii> vii;

int n;
ll T;
string s;
ll x, y;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool possible(int v)
{
	ll curx, cury;
	curx = cury = 0;
	int i;
	for(i = v; i < n; ++i)
	{
		int idx = 3;
		if(s[i] == 'U')
		{
			idx = 0;
		}
		else if(s[i] == 'R')
		{
			idx = 1;
		}
		else if(s[i] == 'D')
		{
			idx = 2;
		}
		curx += dc[idx];
		cury += dr[idx];
	}
	ll v1, v2, v3;
	v1 = llabs(x - curx);
	v2 = llabs(y - cury);
	v3 = llabs(v1+v2);
	if(v3 <= v && (((v-v3)&1LL) == 0))
	{
		return true;
	}
	i = 0;
	int j = v;
	while(j < n)
	{
		int idx = 3;
		if(s[i] == 'U')
		{
			idx = 0;
		}
		else if(s[i] == 'R')
		{
			idx = 1;
		}
		else if(s[i] == 'D')
		{
			idx = 2;
		}
		curx += dc[idx];
		cury += dr[idx];
		idx = 3;
		if(s[j] == 'U')
		{
			idx = 0;
		}
		else if(s[j] == 'R')
		{
			idx = 1;
		}
		else if(s[j] == 'D')
		{
			idx = 2;
		}
		j++;
		curx -= dc[idx];
		cury -= dr[idx];
		v1 = llabs(x - curx);
		v2 = llabs(y - cury);
		v3 = llabs(v1+v2);
		if(v3 <= v && (((v-v3)&1LL) == 0))
		{
			return true;
		}
		i++;
	}
	return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
	while(cin >> n)
	{
		cin >> s;
		cin >> x >> y;
		if(llabs(x) + llabs(y) > n || (llabs((n-llabs(x)-llabs(y)))&1LL))
		{
			cout << "-1\n";
			continue;
		}
		ll curx, cury;
		curx = cury = 0;
		for(int i = 0; i < n; ++i)
		{
			int idx = 3;
			if(s[i] == 'U')
			{
				idx = 0;
			}
			else if(s[i] == 'R')
			{
				idx = 1;
			}
			else if(s[i] == 'D')
			{
				idx = 2;
			}
			curx += dc[idx];
			cury += dr[idx];
		}
		if(x == curx && y == cury)
		{
			cout << "0\n";
			continue;
		}
		int l = 1;
		int h = n;
		while(h-l > 1)
		{
			int mid = (h+l) >> 1;
			if(possible(mid)) h = mid;
			else l = mid+1;
		}
		cout << (possible(l) ? l : h) << '\n';
	}
}
