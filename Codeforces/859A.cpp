#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <stdlib.h>
#include <math.h>
#include <tuple>

using namespace std;

int main()
{
	int K;
	scanf("%d", &K);
	int a = -1;
	for(int i = 0; i < K; i++)
	{
		int b;
		scanf("%d", &b);
		if(a < b)
			a = b;
	}
	printf("%d\n", (a < 25 ? 0 : a - 25));
	return 0;
}
