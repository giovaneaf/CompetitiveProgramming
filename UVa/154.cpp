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
	string s;
	map<char, int> mm;
	mm['r'] = 0; mm['o'] = 1; mm['y'] = 2; mm['g'] = 3; mm['b'] = 4;
	mm['P'] = 0; mm['G'] = 1; mm['S'] = 2; mm['A'] = 3; mm['N'] = 4;
	while(cin >> s)
	{
		if(s == "#") break;
		int freq[10][10] = {};
		int v[110][10];
		int n = 0;
		while(s[0] != 'e')
		{
			int pos = 0;
			FOR(i, 0, 5)
			{
				int a, b;
				a = mm[s[pos]];
				b = mm[s[pos+2]];
				//printf("%c %c\n", s[pos], s[pos+2]);
				v[n][a] = b;
				freq[a][b]++;
				pos += 4;
			}
			cin >> s;
			//printf("%s\n", s.c_str());
			n++;
		}
		int ans = 1000000000;
		int ians = 0;
		FOR(i, 0, n)
		{
			int diff = 0;
			FOR(j, 0, 5)
			{
				int pos = v[i][j];
				//printf("%d %d %d\n", i, j, v[i][j]);
				FOR(k, 0, 5)
				{
					if(k == pos) continue;
					diff += freq[j][k];
				}
			}
			if(ans > diff)
			{
				ans = diff;
				ians = i;
			}
		}
		printf("%d\n", ians+1);
	}
    return 0;
}
