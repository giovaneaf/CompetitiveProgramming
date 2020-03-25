#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define MAXN 200010

int main()
{
	int n, t;
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> t)
	{
		if(abs(n-t) <= 1) printf("0\n");
		else printf("%d\n", abs(n-t)-1);
	}
	return 0;
}