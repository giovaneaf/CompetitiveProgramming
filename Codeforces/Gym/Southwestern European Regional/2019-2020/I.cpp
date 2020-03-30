#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n1, n2, n12;
	while(cin >> n1 >> n2 >> n12)
	{
		double x;
		x = (n1+1)*(n2+1)/(n12+1);
		printf("%d\n", (int) floor(x-1));
	}
    return 0;
}