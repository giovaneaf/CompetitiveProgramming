#include <stdio.h>

int main()
{
	long long int L, C, X, Y;
	scanf("%lld %lld %lld %lld", &L, &C, &X, &Y);
	if((X*C+Y)%2)
		printf("Esquerda");
	else
		printf("Direita");
	putchar('\n');
	return 0;
}