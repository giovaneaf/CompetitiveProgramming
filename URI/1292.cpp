#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double F;
    while(!(cin >> F).eof())
    {
        double L;
        L = sin(108*M_PI/180)/sin(63*M_PI/180)*F;
        printf("%.10lf\n",L);
    }
    return 0;
}
