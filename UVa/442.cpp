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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	ii v[26];
	FOR(i, 0, n)
	{
		char ch;
		cin >> ch;
		cin >> v[ch-'A'].fst >> v[ch-'A'].snd;
	}
	string str;
	while(cin >> str)
	{
		if(str.size() == 1)
		{
			printf("0\n");
			continue;
		}
		stack<ii> s;
		bool can = true;
		ll ans = 0LL;
		for(char c: str)
		{
			if(c == '(')
			{
				s.push(mp(-1, -1));
			}
			else if(c == ')')
			{
				ii B = s.top();
				s.pop();
				ii A = s.top();
				s.pop();
				if(A.snd != B.fst)
				{
					can = false;
					break;
				}
				ans += A.fst*A.snd*B.snd;
				B = mp(A.fst, B.snd);
				while(s.size() && s.top().fst != -1)
				{
					A = s.top();
					if(A.snd != B.fst)
					{
						can = false;
						break;
					}
					ans += A.fst*A.snd*A.snd;
					B = mp(A.fst, B.snd);
				}
				s.pop();
				s.push(B);
			}
			else
			{
				s.push(v[c-'A']);
			}
		}
		if(!can)
		{
			printf("error\n");
		}
		else
		{
			printf("%lld\n", ans);
		}
	}
    return 0;
}