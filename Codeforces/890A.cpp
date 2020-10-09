#include <bits/stdc++.h>

int main()
{
	int v[6];
	int sum = 0;
	bool can = false;
	for(int i = 0; i < 6; i++)
	{
		scanf("%d",&v[i]);
		sum += v[i];
	}
	if(sum%2 == 0)
	{
		sum /= 2;
		for(int i = 0; i < 4; i++)
			for(int j = i+1; j < 5; j++)
				for(int k = j+1; k < 6; k++)
					if(v[i]+v[j]+v[k] == sum)
						can = true;
	}
	if(can)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}