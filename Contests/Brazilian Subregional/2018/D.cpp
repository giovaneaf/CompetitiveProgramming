#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
    {
		int ans, v;
		ans = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> v;
			if(v > 1) ans++;
		}
		printf("%d\n", ans);
    }
    return 0;
}
