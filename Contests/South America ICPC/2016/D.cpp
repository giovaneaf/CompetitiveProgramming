/*
The area of the polygon is proportional to 1/2*P(i)*P(i+1)*sin(angle) where i and i+1 are the numbers
of a permutations of the given values. So you note that the best permutation is to put the highest value
in the first, the second highest in the last, the third highest in the second, the fourth highest in the second-last
and so on and you'll greedily get the best answer.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
	{
		int values[n];
		for(int i = 0; i < n; ++i)
		{
			cin >> values[i];
		}
		sort(values, values+n);
		vector<int> point(n);
		int j = 0;
		for(int i = n-1; i >= 0; i -= 2)
		{
			point[j] = values[i];
			j++;
		}
		j = n - 1;
		for(int i = n-2; i >= 0; i -= 2)
		{
			point[j] = values[i];
			j--;
		}
		double gap = 2.0*M_PI/n;
		double angle = gap/2.0;
		double area = 0.0;
		for(int i = 0; i < n; ++i)
		{
			int nxt = (i + 1 >= n ? 0 : i+1);
			area += cos(angle)*point[i]*sin(angle+gap)*point[nxt] - cos(angle+gap)*point[nxt]*sin(angle)*point[i];
			angle += gap;
		}
		printf("%.3f\n", fabs(area)/2.0);
	}
    return 0;
}
