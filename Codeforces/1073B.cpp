#include <bits/stdc++.h>
 
#define mp(a, b) make_pair(a, b)

#define MAXN 510
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

int n;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
	while(cin >> n)
	{
		vector<int> b(n);
		vector<int> idx(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> b[i];
			idx[--b[i]] = i;
		}
		int id = 0;
		for(int i = 0; i < n; ++i)
		{
			int val;
			cin >> val;
			val--;
			int sz = 0;
			for(; id <= idx[val]; id++)
			{
				sz++;
			}
			cout << sz << ' ';
		}
		cout << '\n';
	}
}
