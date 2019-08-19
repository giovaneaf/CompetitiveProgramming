/*
https://br.spoj.com/problems/ASSALTMG/
There are at most 20 directors so we can brute force all 2^20 possibilities of directors then verify how many distinct
key each set of director has. 
Hint: using bitwise operations are faster.
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int numBits(int n)
{
	int bits = 0;
	for(int i = 0; i < 32; ++i)
		if(n & (1 << i))
			bits++;
	return bits;
}
 
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int m, d;
		scanf("%d %d", &m, &d);
		int keys[35];
		int minD = 50;
		for(int i = 0; i < d; ++i)
		{
			keys[i] = 0;
			int numKeys;
			scanf("%d", &numKeys);
			for(int j = 0; j < numKeys; ++j)
			{
				int key;
				scanf("%d", &key);
				keys[i] |= (1 << key);
			}
		}
		for(int i = 0; i < (1 << d); ++i)
		{
			int numDir = numBits(i);
			if(numDir >= minD)
				continue;
			int keysStolen = 0;
			for(int j = 0; j < d; ++j)
			{
				if(i & (1 << j))
				{
					keysStolen |= keys[j];
				}
			}
			keysStolen = numBits(keysStolen);
			if(keysStolen >= m)
			{
				minD = numDir;
			}
		}
		if(minD == 50)
		{
			printf("Desastre!");
		}
		else
		{
			printf("%d", minD);
		}
		putchar('\n');
	}
	return 0;
} 