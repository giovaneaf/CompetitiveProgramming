#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int N, T, A, X, Y;
	scanf("%d %d %d %d %d", &N, &T, &A, &X, &Y);
	int t[T];
	for(int i = 0; i < T; i++)
	{
		scanf("%d", &t[i]);
	}
	bool bit;
	int j = 0;
	int sum = 0;
	int already[X];
	for(int i = 1; i < X; i++)
		already[i] = -2;
	already[0] = -1;
	while(true)
	{
		sum = (sum+A)%X;
		if(already[sum] != -2 && j - already[sum] >= Y)
		{
			printf("%d %d\n", already[sum]+1, j);
			break;
		}
		else if(already[sum] == -2)
		{
			already[sum] = j;
		}
		bit = false;
		for(int i = 0; i < T; i++)
		{
			bit ^= (((A) & (1<<t[i])) > 0);
		}
		A >>= 1;
		A |= (bit << (N-1));
		j++;
	}
	return 0;
}