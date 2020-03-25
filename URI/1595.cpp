#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int s, c, r;
		scanf("%d %d %d", &s, &c, &r);
		vector<int> v(s);
		for(int i = 0; i < s; ++i)
		{
			scanf("%d", &v[i]);
		}
		sort(v.begin(), v.end());
		double time = 0.0f;
		for(int i = 0; i < s; ++i)
		{
			if(c > i)
			{
				v[i] += r;
			}
			time += 1.0f/((double) v[i]);
		}
		printf("%.2f\n", time);
	}
	return 0;
}