#include <bits/stdc++.h>

using namespace std;

int f(int n, int digit)
{
	int tmp = n/10;
	int rem = n%10;
	int mult = 1;
	int cnt = n/10 + (rem >= digit ? 1 : 0);
	if(digit == 0) cnt--;
	while(tmp != 0)
	{
		mult *= 10;
		int qty = mult*(n/(mult*10));
		int cur = tmp%10;
		if(cur > digit)
			qty += mult;
		else if(cur == digit)
			qty += rem+1;
		if(digit == 0)
			qty = max(0, qty - mult);
		cnt += qty;
		rem += mult*cur;
		tmp = tmp/10;
	}
	return cnt;
}

int main()
{
	int a, b;
	while(true)
	{
		scanf("%d %d", &a, &b);
		if(a == 0 and b == 0)
			break;
		for(int i = 0; i < 10; ++i) 
		{
			if(i > 0)
				putchar(' ');
			printf("%d", f(b, i) - f(a-1, i));
		}
		putchar('\n');
	}
	return 0;
}