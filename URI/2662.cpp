#include <stdio.h>

int getKey(int ans)
{
	switch(ans)
	{
		case 0: printf("do"); break;
		case 1: printf("do#"); break;
		case 2: printf("re"); break;
		case 3: printf("re#"); break;
		case 4: printf("mi"); break;
		case 5: printf("fa"); break;
		case 6: printf("fa#"); break;
		case 7: printf("sol"); break;
		case 8: printf("sol#"); break;
		case 9: printf("la"); break;
		case 10: printf("la#"); break;
		case 11: printf("si"); break;
	}
	putchar('\n');
}

int sync(int i, int j)
{
	if(i == j || (i+2)%12 == j || (i+4)%12 == j || (i+5)%12 == j || (i+7)%12 == j || (i+9)%12 == j || (i+11)%12 == j)
		return true;
	return false;
}

int main()
{
	int N;
	scanf("%d", &N);
	int v[12];
	int d[] = {2, 2, 1, 2, 2, 2, 1};
	for(int i = 0; i < 12; i++)
		v[i] = 0;
	for(int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		v[(a-1)%12]++;
	}
	int ans = -1;
	for(int i = 0; i < 12; i++)
	{
		bool can = true;
		for(int j = 0; j < 12; j++)
		{
			if(v[j] > 0 && !sync(i, j))
			{
				can = false;
				break;
			}
		}
		if(can)
		{
			ans = i;
			break;
		}
	}
	if(ans == -1)
	{
		printf("desafinado\n");
	}
	else
	{
		getKey(ans);
	}
	return 0;
}