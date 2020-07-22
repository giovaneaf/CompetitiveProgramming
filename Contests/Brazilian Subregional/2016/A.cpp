#include <iostream>
using namespace std;

int main()
{
	int A,B,C,max,med,min;
	while (!(cin >> A >> B >> C).eof())
	{
		if (A == B || A == C || B == C || A == B+C || B == A+C || C == A+B)
			cout << "S" << endl;
		else
			cout << "N" << endl;
	}
	return 0;
}