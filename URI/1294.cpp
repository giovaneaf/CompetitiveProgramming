#include <bits/stdc++.h>

using namespace std;

int main()
{
	double l, w;
	while(scanf("%lf %lf", &l, &w) != EOF)
	{
		double tmp = sqrt(l*l - l*w + w*w);
		double maxRoot = (l+w-tmp)/6.0f;
		double minRoot = (l+w+tmp)/6.0f;
		if(maxRoot > min(l/2.0, w/2.0f))
			swap(maxRoot, minRoot);
		printf("%.3lf 0.000 %.3lf\n", maxRoot, min(l/2.0, w/2.0f));
	}
	return 0;
}