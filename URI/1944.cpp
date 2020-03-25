#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string l;
	getline(cin, l);
	stack<char> s;
	s.push('F');
	s.push('A');
	s.push('C');
	s.push('E');
	char arr[4];
	int cont = 0;
	for(int i = 0; i < N; i++)
	{
		char l[4];
		cin >> l[0] >> l[1] >> l[2] >> l[3];
		bool pal = true;
		for(int j = 0; j < 4; j++)
		{
			arr[j] = s.top();
			s.pop();
			if(arr[j] != l[j])
				pal = false;
		}
		if (pal)
		{
			cont++;
			if(s.empty())
			{
				s.push('F');
				s.push('A');
				s.push('C');
				s.push('E');
			}
		}
		else
		{
			for(int j = 0; j < 4; j++)
			{
				s.push(arr[3-j]);
			}
			for(int j = 0; j < 4; j++)
			{
				s.push(l[j]);
			}
		}
	}
	cout << cont << endl;
	return 0;
}
