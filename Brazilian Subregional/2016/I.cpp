#include <iostream>
#include <cstdio>
using namespace std;

int min(const int a, const int b)
{
	if (a<b)
		return a;
	return b;
}

int main()
{
	int N,i,dir,esq,max,tam;
	while(!(cin >> N).eof())
	{
		int Quad[50000];
		int Dir[50000];
		int Esq[50000];
		for (i=0;i<N;i++)
			cin >> Quad[i];
		dir=esq=0;
		for (i=0;i<N;i++)
		{
			if (Quad[i]>dir)
				dir++;
			else
				dir = Quad[i];
			Dir[i] = dir;
			
			if (Quad[N-1-i]>esq)
				esq++;
			else
				esq = Quad[N-i-1];
			Esq[N-1-i] = esq;
		}
		max = (N+1)/2;
		tam = 1;
		for (i=0;i<N && tam < max;i++)
		{
			if (min(Dir[i],Esq[i])>tam)
				tam = min(Dir[i],Esq[i]);
		}
		cout << tam << endl;
	}
	return(0);
}