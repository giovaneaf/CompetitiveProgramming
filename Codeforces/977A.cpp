#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define rREP(i, a, n) for(int i = a; i >= n; --i)


int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; ++i)
	{
		n = (n%10 == 0 ? n/10 : n-1);
	}
	cout << n << "\n";
	return 0;
}
