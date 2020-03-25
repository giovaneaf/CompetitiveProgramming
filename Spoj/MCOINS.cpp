#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1000010
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int k, l, m;
int memo[MAXN];
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> k >> l >> m)
	{
		FOR(i, 0, MAXN)
		{
			set<int> s;
			if(i-1 >= 0) s.insert(memo[i-1]);
			if(i-k >= 0) s.insert(memo[i-k]);
			if(i-l >= 0) s.insert(memo[i-l]);
			int mex = 0;
			auto it = s.begin();
			while(it != s.end() && mex == *it)
			{
				mex++; it++;
			}
			memo[i] = mex;
			//printf("%d %d\n", i, memo[i]);
		}
		while(m--)
		{
			int v;
			cin >> v;
			printf("%c", memo[v] > 0 ? 'A' : 'B');
		}
		putchar('\n');
	}
	return 0;
} 