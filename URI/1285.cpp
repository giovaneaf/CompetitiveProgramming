#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
    	int ans = 0;
    	for(int i = n; i <= m; ++i)
    	{
    		int aux = i;
    		vector<bool> used;
    		used.assign(10, false);
    		bool possible = true;
    		while(aux > 0)
    		{
    			int digit = aux%10;
    			if(used[digit])
    			{
    				possible = false;
    				break;
    			}
    			used[digit] = true;
    			aux /= 10;
    		}
    		if(possible) ans++;
    	}
    	printf("%d\n", ans);
	}
	return 0;
}