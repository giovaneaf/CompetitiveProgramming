#include <stdio.h>

int main()
{
	int a = 0, b = 0;
	for(int i = 0; i < 5; i++)
	{
		int bit;
		scanf("%d", &bit);
		a += (bit << i);
	}
	for(int i = 0; i < 5; i++)
	{
		int bit;
		scanf("%d", &bit);
		b += (bit << i);
	}
	a ^= b;
	if(a == (1 << 5) - 1)
		printf("Y\n");
	else
		printf("N\n");
	return 0;
}