#include <bits/stdc++.h>

#define FOR(a, b, c) for(int a = b; a < c; ++a)

using namespace std;

int main()
{
	int n;
	cin >> n;
	int v[n];
	FOR(i, 0, n) cin >> v[i];
	int imn = 0;
	FOR(i, 1, n)
		if(v[i] < v[imn])
			imn = i;
	int times = (v[imn] - imn)/n + ((v[imn] - imn)%n > 0 ? 1 : 0);
	int value = times*n;
	int ans = imn;
	bool search = true;
	if(times > 0)
	{
	    int newvalue = (times-1)*n;
	    FOR(i, imn+1, n)
	    {
	        if(v[i] - (newvalue + i) <= 0)
	        {
	            ans = i;
	            search = false;
	            break;
	        }
	    }
	}
	if(search)
    	FOR(i, 0, imn)
    	{
    		if(v[i] - (value+i) <= 0)
    		{
    			ans = i;
    			break;
    		}
    	}
	printf("%d\n", ans+1);
    return 0;
}
