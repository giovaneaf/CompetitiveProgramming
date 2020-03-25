#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		map<string, double> m;
		int N;
		cin >> N;
		int i;
		string s;
		getline(cin, s);
		double p;
		for(i = 0; i < N; i++)
		{
			cin >> s >> p;
			m[s] = p;
		}
		int M;
		cin >> M;
		getline(cin, s);
		int q;
		double total = 0;
		for(i = 0; i < M; i++)
		{
			cin >> s >> q;
			total += (q*m[s]);
		}
		printf("R$ %.2f\n", total);
	}
	return 0;
}