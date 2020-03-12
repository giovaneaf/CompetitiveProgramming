#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b;
    while(cin >> a)
    {
		cin >> b;
		int ans = 0;
		for(int i = 0; i <= a.size() - b.size(); ++i)
		{
			bool diff = true;
			for(int j = 0; j < b.size(); ++j)
			{
				if(a[i+j] == b[j])
				{
					diff = false;
					break;
				}
			}
			ans += diff;
		}
		printf("%d\n", ans);
    }
    return 0;
}