/*
The answer is min(abs(a+b - (c+d)), min(abs(a+c - (b+d)), abs(a+d - (b+c))))
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    long long int menor;
    long long int a,b,c,d;
    while(cin >> a >> b >> c >> d)
	{
		menor = abs(a+b - (c+d));
		if (abs(a+c - (b+d)) < menor)
			menor = abs(a+c - (b+d));
		if (abs(a+d - (b+c)) < menor)
			menor = abs(a+d - (b+c));
		cout << menor << endl;
	}
    return 0;
}
