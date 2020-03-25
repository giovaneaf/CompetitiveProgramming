#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	map<int, int> mapa;
	int valor;
	for(int i = 0; i < n; ++i)
	{
		cin >> valor;
		mapa[valor]++;
	}
	map<int, int>::iterator it;
	for(it = mapa.begin(); it != mapa.end(); ++it)
	{
		printf("%d aparece %d vez(es)\n", it->first, it->second);
	}
	return 0;
}