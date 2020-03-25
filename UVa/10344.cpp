#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 50010
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9

int n, m, q;
int vv[5];
int op[4];

bool solve(int pos)
{
	//printf("%d\n", pos);
	if(pos == 4)
	{
		/*FOR(i, 0, 4)
		{
			printf("%d ", op[i]);
		}
		putchar('\n');*/
		vi v(5);
		FOR(i, 0, 5) v[i] = vv[i];
		do
		{
			int ans = v[0];
			FOR(i, 1, 5)
			{
				if(op[i-1] == 0)
					ans *= v[i];
				else if(op[i-1] == 1)
					ans += v[i];
				else if(op[i-1] == 2)
					ans -= v[i];
			}
			if(ans == 23) 
			{
				return true;
			}
		} while(next_permutation(v.begin(), v.end()));
		return false;
	}
	else
	{
		FOR(i, 0, 3)
		{
			op[pos] = i;
			if(solve(pos+1)) return true;
		}
		return false;
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> vv[0] && vv[0])
	{
		FOR(i, 1, 5) cin >> vv[i];
		sort(vv, vv+5);
		bool can = solve(0);
		printf("%s\n", !can ? "Impossible" : "Possible");
	}
    return 0;
}
