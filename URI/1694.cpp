#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

unsigned long long int Combination(int n, int k)
{
	if (n < k) return 0;
	if (n == k) return 1;
	if (k*2 > n) k = n-k;
	
	unsigned long long int result = n;
	for (int i = 2; i <= k; i++)
	{
		result *= (n-i+1);
		result /= i;
	}
	return result;
}

bool primeNumber(int N)
{
	if (N == 0 || N == 1)
		return false;
	if (N%2 == 0)
	{
		if (N == 2)
			return true;
		else
			return false;
	}
	for (int i = 3; i <= round(sqrt(N)); i += 2)
		if (N%i == 0)
			return false;
	return true;
}

int main()
{
	int N, M, K;
	while(cin >> N >> M >> K)
	{
		if (N == 0 && M == 0 && K == 0)
			break;
		bool prime[N][M];
		int row[N];
		int col[M];
		int i, j, k;
		for (i = 0; i < N; i++)
			row[i] = 0;
		for (j = 0; j < M; j++)
			col[j] = 0;	
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				prime[i][j] = primeNumber(i*M + j);
			}
		}
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (!prime[i][j])
					row[i]++;
			}
		}
		for (j = 0; j < M; j++)
		{
			for (i = 0; i < N; i++)
			{
				if (!prime[i][j])
					col[j]++;
			}
		}
		unsigned long long int times = 0;
		for (i = 0; i < N; i++)
		{
			times += Combination(row[i],K);
		}
		for (j = 0; j < M; j++)
		{
			times += Combination(col[j],K);
		}
		
		if (K == 1)
			times /= 2;
		
		cout << times << endl;
	}
	return 0;
}