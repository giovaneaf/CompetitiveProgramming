#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int A,B,C,D;
	cin >> A >> B >> C >> D;
	cout << (abs(C-A)+abs(B-D)) << endl;
	return 0;
}
