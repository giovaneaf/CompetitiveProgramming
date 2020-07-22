#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 1010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9
 
int n, m, k;
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> k)
	{
		string s1;
		string s2;
		cin >> s1 >> s2;
		int sz = s1.size();
		int e = 0;
		FOR(i, 0, sz)
		{
			e += (s1[i] == s2[i]);
		}
		int ne = sz - e;
		printf("%d\n", min(e, k) + ne-max(0, k-e));
	}
	return 0;
} 