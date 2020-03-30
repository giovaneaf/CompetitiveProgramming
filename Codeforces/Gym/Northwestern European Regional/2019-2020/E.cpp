#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define MAXN 1000010
#define LOGMAXN 20
#define MAXM 100010
#define INF 1000000007
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
 
#define ITER 1000000
#define DEBUG 0

int n, m;

inline bool eq(double a, double b)
{
	return fabs(a-b) < EPS;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<double> v(4);
	double sum = 0.0, mn;
	FOR(i, 0, 4)
	{
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	cin >> mn;
	double avg = (sum - v[0])/3.0;
	if(avg < mn || eq(avg, mn))
	{
		printf("infinite\n");
	}
	else
	{
		avg = (sum - v[3])/3.0;
		if(avg > mn && !eq(avg, mn))
			printf("impossible\n");
		else
		{
			printf("%.2f\n", mn*3.0-v[1]-v[2]);
		}
	}
	return 0;
}