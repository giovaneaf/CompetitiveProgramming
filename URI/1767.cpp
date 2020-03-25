#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int T;
	cin >> T;
	if(T >= 0)
	{
		while(T--)
		{
			int N;
			cin >> N;
			int Q[N];
			int W[N];
			for(int i = 0; i < N; i++)
				cin >> Q[i] >> W[i];
			int M[N+1][51];
			memset(M, 0, sizeof(M));
			for(int i = 1; i < N+1; i++)
			{
				for(int j = 1; j < 51; j++)
				{
					if(W[i-1] > j)
						M[i][j] = M[i-1][j];
					else
					{
						M[i][j] = max(Q[i-1] + M[i-1][j-W[i-1]], M[i-1][j]);
					}
				}
			}
			int weigth = 0;
			int presents = 0;
			int j = 50;
			for(int i = N; i > 0; i--)
			{
				if(M[i][j] == M[i-1][j])
				{
					presents++;
				}
				else
				{
					j -= W[i-1];
					weigth += W[i-1];
				}
			}
			printf("%d brinquedos\n", M[N][50]);
			printf("Peso: %d kg\n", weigth);
			printf("sobra(m) %d pacote(s)\n\n", presents);
		}
	}
	return 0;
}