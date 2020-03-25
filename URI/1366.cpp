#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF and n)
	{
    	int total = 0;
    	for(int i = 0; i < n; ++i)
    	{
    	    int c, v;
    	    scanf("%d %d", &c, &v);
    	    if(v&1) v--;
    	    total += v;
    	}
    	printf("%d\n", total/4);
	}
	return 0;
}