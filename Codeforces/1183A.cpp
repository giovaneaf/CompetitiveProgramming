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


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, tmp, sum;
	cin >> a;
	while(true)
	{
		tmp = a;
		sum = 0;
		while(tmp > 0)
		{
			sum += tmp%10;
			tmp /= 10;
		}
		if((sum%4) == 0)
		{
			printf("%d\n", a);
			break;
		}
		a++;
	}
	return 0;
}
