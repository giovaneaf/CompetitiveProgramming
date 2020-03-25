#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	unsigned long long int R,G,B;
	cin >> hex >> R >> G >> B;
	R = (R/G)*(R/G);
	G = (G/B)*(G/B)*R;
	cout << hex << 1+R+G << endl;
	return (0);
}
