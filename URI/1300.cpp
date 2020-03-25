#include <iostream>
 
using namespace std;
 
int main() 
{

    int a;

    while(cin>>a)
    {
		cout << (((a%6) == 0) ? 'Y': 'N') << endl;
    }
 
    return 0;
}