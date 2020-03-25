#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", 2*min(B + 2*C, min(A + C, 2*A + B)));
	return 0;
}