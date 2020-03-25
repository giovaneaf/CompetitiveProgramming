#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int N = 0;
	int sum = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(i < s.size()-1 && s[i] == '1' && s[i+1] == '0')
		{
			sum += 10;
			i++;
		}
		else
		{
			sum += (s[i] - '0');
		}
		N++;
	}
	printf("%.2lf\n", (double)sum/N);
	return 0;
}