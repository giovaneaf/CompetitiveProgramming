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
#define MAXN 200010
#define LOGMAXN 20
#define MAXM 1000010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

int T;

int getIdx(char c)
{
	if(c == 'R')
		return 1;
	if(c == 'P')
		return 2;
	return 0;
}

int getChar(int idx)
{
	if(idx == 0)
		return 'R';
	if(idx == 1)
		return 'P';
	return 'S';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> T)
	{
		while(T--)
		{
			int n;
			cin >> n;
			int v[3];
			FOR(i, 0, 3)
				cin >> v[i];
			string s;
			cin >> s;
			string ans;
			ans.assign(n, '?');
			int win = 0;
			FOR(i, 0, n)
			{
				int curIdx = getIdx(s[i]);
				if(v[curIdx] > 0)
				{
					v[curIdx]--;
					win++;
					ans[i] = getChar(curIdx);
				}
			}
			if(win >= (n+1)/2)
			{
				printf("YES\n");
				FOR(i, 0, n)
				{
					if(ans[i] == '?')
					{
						FOR(j, 0, 3)
						{
							if(v[j] > 0)
							{
								v[j]--;
								ans[i] = getChar(j);
								break;
							}
						}
					}
				}
				printf("%s\n", ans.c_str());
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}
