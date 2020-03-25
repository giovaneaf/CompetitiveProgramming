#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void Eratosthenes(vector<int>& Primes)
{
	int cont = 0;
	bool Prime[32610];
	memset(Prime, true, sizeof(bool)*32610);
	Prime[1] = false;
	for(int i = 2; i < 32610 && cont < 3500; i++)
	{
		if(Prime[i])
		{
			Primes[cont] = i;
			cont++;
			for(int j = 2; i*j < 32610; j++)
			{
				Prime[i*j] = false;
			}
		}
	}
}

int main()
{
	vector<int> Primes(3500);
	Eratosthenes(Primes);
	int N;
	while(cin >> N && N != 0)
	{
		vector<int> v(N);
		for(int i = 0; i < N; i++)
			v[i] = i;
		int cur = -1;
		int size = N;
		for(int i = 0; i < N-1; i++)
		{
			cur = (cur + Primes[i])%(size);
			v.erase(v.begin()+cur);
			size--;
			cur--;
		}
		cout << v[0]+1 << endl;
	}
	return 0;
}