#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string l;
	getline(cin,l);
	getline(cin,l);
	while(N--)
	{
		map<string, int> m;
		int cont = 0;
		string tree;
		getline(cin, tree);
		while(tree[0] != '\0')
		{
			if(m.find(tree) != m.end())
			{
				m[tree]++;
			}
			else
			{
				m[tree] = 1;
			}
			cont++;
			getline(cin, tree);
		}
		map<string, int>::iterator it;
		for(it = m.begin(); it != m.end(); it++)
		{
			cout << it->first;
			printf(" %.4f\n", (100.0*it->second)/cont);
		}
		if (N>0)
			cout << endl;
	}
	return 0;
}
