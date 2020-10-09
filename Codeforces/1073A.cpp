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
		string s;
		cin >> s;
		bool possible = false;
		for(int i = 0; i < n-1; ++i)
		{
			if(s[i] != s[i+1])
			{
				cout << "YES\n";
				cout << s[i] << s[i+1] << '\n';
				possible = true;
				break;
			}
		}
		if(!possible) cout << "NO\n";
	}
}
