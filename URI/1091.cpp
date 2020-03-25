#include <stdio.h>

int main()
{
	int N;
	while(scanf("%d", &N) && N)
	{
		int Xc, Yc;
		scanf("%d %d", &Xc, &Yc);
		for(int i = 0; i < N; i++)
		{
			int X, Y;
			scanf("%d %d", &X, &Y);
			if(X == Xc || Y == Yc)
				printf("divisa\n");
			else if(X > Xc && Y > Yc)
				printf("NE\n");
			else if(X < Xc && Y > Yc)
				printf("NO\n");
			else if(X > Xc && Y < Yc)
				printf("SE\n");
			else
				printf("SO\n");
		}
	}
	return 0;
}