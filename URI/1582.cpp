#include <iostream>

using namespace std;

int MDC(int a,int b)
{
    while(b != 0)
    {
        int aux = a;
        a = b;
        b = aux%b;
    }
    return a;
}

int main()
{
    int x, y, z;
    while(!(cin >> x >> y >> z).eof())
    {
        if (((x*x) != ((y*y)+(z*z))) && ((y*y) != ((x*x)+(z*z))) && ((z*z) != ((y*y)+(x*x))))
            cout << "tripla\n";
        else
        {
            cout << "tripla pitagorica";
            if (MDC(x,MDC(y,z)) == 1)
                cout << " primitiva";
            cout << endl;
        }
    }
    return 0;
}