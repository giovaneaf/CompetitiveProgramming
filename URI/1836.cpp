#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int i;
    for(i=0;i<N;i++)
    {
        string name;
        int lvl;
        cin >> name >> lvl;
        int x[4],y[4],z[4];
        cin >> x[0] >> y[0] >> z[0];
        cin >> x[1] >> y[1] >> z[1];
        cin >> x[2] >> y[2] >> z[2];
        cin >> x[3] >> y[3] >> z[3];
        cout << "Caso #" << i+1 << ": " << name << " nivel " << lvl << endl;
        cout << "HP: " << floor(10+(y[0]+x[0]+sqrt(z[0])/8.0+50)*lvl/50.0) << endl;
        cout << "AT: " << floor(5+(y[1]+x[1]+sqrt(z[1])/8.0)*lvl/50.0) << endl;
        cout << "DF: " << floor(5+(y[2]+x[2]+sqrt(z[2])/8.0)*lvl/50.0) << endl;
        cout << "SP: " << floor(5+(y[3]+x[3]+sqrt(z[3])/8.0)*lvl/50.0) << endl;
    }
    return 0;
}