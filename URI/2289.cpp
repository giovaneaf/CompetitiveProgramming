#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define EPS 1e-9
#define ull unsigned long long

const int INF = 1e9;
const ll llINF = 1e18;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ull a, b;
	while(cin >> a >> b)
	{
		if(a == 0 && b == 0) break;
		int ans = 0;
		for(int i = 0; i < 64; ++i)
		{
			ull o, t;
			o = a & (1ULL << i);
			t = b & (1ULL << i);
			if(o > 0 && t == 0) ans++; 
			else if(o == 0 && t > 0) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}