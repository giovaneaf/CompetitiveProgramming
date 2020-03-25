#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int lap;
    int X,Y;
    while (!(cin >> X >> Y).eof())
    {
        lap = 1;
        double Ylaps;
        Ylaps = (X/1.0)/Y;
        int Ylap;
        Ylap = (int)Ylaps;
        while (Ylap < lap && Ylap >= lap - 1)
        {
            Ylaps += (X/1.0)/Y;
            Ylap = (int)Ylaps;
            lap++;
        }
        Ylaps -= (X/1.0)/Y;
        if (fabs (Ylaps - ((lap-2)/1.0)) < 0.001)
            lap--;
        cout << lap << endl;
    }
    return 0;
}
