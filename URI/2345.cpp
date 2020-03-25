#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    long long int menor;
    long long int a,b,c,d;
    cin >> a >> b >> c >> d;
    menor = abs(a+b - (c+d));
    if (abs(a+c - (b+d)) < menor)
        menor = abs(a+c - (b+d));
    if (abs(a+d - (b+c)) < menor)
        menor = abs(a+d - (b+c));
    cout << menor << endl;
    return 0;
}
