// Computed minimum cost using the function f(m) = (k*p)/m + x*m taking derivative
// in respect to m and letting the derivative be 0 and got:
// m = sqrt(k*p/x)
// So the minimum value is the nearest integer value of this calculated m
// Time Complexity: O(1) - Compute the values

// Finding minimum/maximum of a function: https://www.mathsisfun.com/calculus/maxima-minima.html

#include <bits/stdc++.h>

using namespace std;

int K, P, X;

double cost(int m)
{
	return (double) K*P/m + X*m;
}

int main()
{
	while(scanf("%d %d %d", &K, &P, &X) != EOF)
	{
		double minimum = sqrt((double) K*P/X);
		printf("%.3f\n", min(cost((int) floor(minimum)), cost((int) ceil(minimum))));
	}
	return 0;
}