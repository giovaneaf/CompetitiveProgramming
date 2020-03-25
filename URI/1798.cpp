#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, T;
	cin >> N >> T;
	int L[N];
	int C[N];
	for(int i = 0; i < N; i++)
		cin >> L[i] >> C[i];
	int M[N+1][T+1];
	memset(M, 0, sizeof(M));
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= T; j++)
		{
			if(L[i-1] > j)
				M[i][j] = M[i-1][j];
			else
			{
				M[i][j] = max(M[i-1][j], C[i-1] + M[i][j-L[i-1]]);
			}
		}
	cout << M[N][T] << endl;
	return 0;
}