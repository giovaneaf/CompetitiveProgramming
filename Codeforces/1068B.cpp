#include <bits/stdc++.h>

#define mp(a, b) make_pair(a, b)

#define MAXN 210
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

ll b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> b)
	{
		double sqr = sqrt(b);
		int cnt = 0;
		for(int i = 1; i < sqr; ++i)
		{
			if(b%i == 0)
			{
				cnt += 2;
			}
		}
		ll sq = (int) sqr;
		if(sq*sq == b)
			cnt++;
		cout << cnt << '\n';
	}
	return 0;
}