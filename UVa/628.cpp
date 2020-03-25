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

void generateall(int pos, string& s, vector<string>& v, int* idx)
{
	if(pos == (int) s.size())
	{
		FOR(i, 0, (int) s.size())
		{
			if(s[i] == '#')
				printf("%s", v[idx[i]].c_str());
			else
				printf("%d", idx[i]);
		}
		putchar('\n');
	}
	else
	{
		if(s[pos] == '#')
		{
			FOR(i, 0, n)
			{
				idx[pos] = i;
				generateall(pos+1, s, v, idx);
			}
		}
		else
		{
			FOR(i, 0, 10)
			{
				idx[pos] = i;
				generateall(pos+1, s, v, idx);
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n)
	{
		vector<string> v(n);
		FOR(i, 0, n) cin >> v[i];
		cin >> m;
		string s;
		printf("--\n");
		FOR(i, 0, m)
		{
			cin >> s;
			int idx[(int) s.size()];
			generateall(0, s, v, idx);
		}
	}
    return 0;
}
