#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int R,B,C;
        int x, y;
        cin >> x >> y;
        R = 9*x*x + y*y;
        B = 2*x*x + 25*y*y;
        C = -100*x + y*y*y;
        if (R > B && R > C)
            cout << "Rafael ganhou\n";
        else if (B > R && B > C)
            cout << "Beto ganhou\n";
        else
            cout << "Carlos ganhou\n";
    }
    return 0;
}