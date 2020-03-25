#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vb vector<bool>
#define fst first
#define snd second
#define MAXN 40
#define LOGMAXN 20
#define FOR(a, b, c) for(int a = b; a < c; ++a)
#define RFOR(a, b, c) for(int a = b; a >= c; --a)
#define mp(a, b) make_pair(a, b)
#define INF 1e9
#define EPS 1e-9


int n, m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	int calls[MAXN];
	int fib[MAXN];
	calls[0] = 1; fib[0] = 0;
	calls[1] = 1; fib[1] = 1;
	FOR(i, 2, MAXN)
	{
		calls[i] = calls[i-1] + calls[i-2] + 1;
		fib[i] = fib[i-1] + fib[i-2];
	}
	while(T--)
	{
		cin >> n;
		printf("fib(%d) = %d calls = %d\n", n, calls[n]-1, fib[n]);
	}
	return 0;
} 