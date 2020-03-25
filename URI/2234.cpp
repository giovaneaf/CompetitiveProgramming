#include <iostream>
#include <cstdio>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
	int A,B;
	float media;
	while (!(cin >> A >> B).eof())
	{
		media = round((double)A/B*100)/100.0;
		cout << fixed << setprecision(2) <<media << endl;
	}
}
