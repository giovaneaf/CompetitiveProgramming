#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int r1,x1,y1,r2,x2,y2;
    double dist;
    while (!(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2).eof())
    {
        dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        dist = sqrt(dist);
        if (r1 >= ceil(dist) + r2)
            cout << "RICO\n";
        else
            cout << "MORTO\n";
    }
    return 0;
}