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
#define MAXN 500010
#define MAXM 44100
#define LOGMAXN 20
#define INF 1e9+7
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL

bool isPrime(int n)
{
	if(n == 2) return true;
	if((n&1) == 0) return false;
	for(int i = 3; i < sqrt(n)+1; ++i)
	{
		if(n%i == 0) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n)
	{
		while(!isPrime(n))
		{
			n--;
		}
		printf("%d\n", n);
	}
	return 0;
}
